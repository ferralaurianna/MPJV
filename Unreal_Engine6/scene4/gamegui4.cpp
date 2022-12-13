#include "gamegui4.h"

const float PI=3.14159;


gamegui4::gamegui4(QWidget *parent): QOpenGLWidget(parent)
{
    // Initialize the instance of the objects to render at the first rendering (gun, ground...)
}

gamegui4::~gamegui4()
{

}


// Initialize OpenGL parameters before the first rendering
void gamegui4::initializeGL()
{
    // Background color
    background=QColor(0,0,0,1);
    glClearColor(background.redF(),background.greenF(),background.blueF(),background.alphaF());

    // VERY IMPORTANT :: allow to draw with an automatic management of depth. DO NOT REMOVE.
    glEnable(GL_DEPTH_TEST);

    // Ambiant light
    glLightfv(GL_LIGHT0,GL_AMBIENT,light_tab);
    glLightfv(GL_LIGHT0,GL_DIFFUSE,light_tab);
    glLightfv(GL_LIGHT0,GL_SPECULAR,light_tab);

    glLightfv(GL_LIGHT0,GL_POSITION,light_tab_pos);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);

    resizeGL(width(),height());
}



void gamegui4::resizeGL(int width, int height)
{
    // Viewport definition
    glViewport(0, 0, width, height);
}


// General rendering management
void gamegui4::paintGL()
{
    // Clear background
    glClearColor(background.redF(),background.greenF(),background.blueF(),background.alphaF());
    // Clear depth
    glClear(GL_DEPTH_BUFFER_BIT|GL_COLOR_BUFFER_BIT);

    // Reinitializisation of the current projection matrix
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(80.f, this->width()/this->height(), 5.f, 10000.f);

    // Reinitializisation of the camera
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(cameraX_,cameraY_,cameraZ_, centralX_,centralY_,centralZ_, 0.,dirY,0.);

    // Colorize every single objects after that in white
    glColor3f(1, 1, 1);

    int i = 0;
    int ind = 0;
    while(i < pactorList->size()){
        Actors* act = pactorList->getActor(ind);
        if(act!=nullptr)
        {
            for( Polygone pol : *(act->getPolygones()))
            {
                DrawPolygone(pol,ind);
            }
            i++;
        }
        ind++;
    }
}

std::vector<Polygone> gamegui4::CreateCubePolygone(float x,float y,float z,float lx,float ly,float lz){

    std::vector<Polygone> polygones;

    //1st vertex
    Vector3D Topleftback = Vector3D(x + lx/2, y + ly/2,z + lz/2);

    //2nd vertex
    Vector3D Topleftfront = Vector3D(x + lx/2, y + ly/2,z - lz/2);

    //3rd vertex
    Vector3D Toprightfront = Vector3D(x - lx/2, y + ly/2,z - lz/2);

    //4th vertex
    Vector3D Toprightback = Vector3D(x - lx/2, y + ly/2,z + lz/2);

    //5th vertex
    Vector3D Botleftback = Vector3D(x + lx/2, y - ly/2,z + lz/2);

    //6th vertex
    Vector3D Botleftfront = Vector3D(x + lx/2, y - ly/2,z - lz/2);

    //7th vertex
    Vector3D Botrightfront = Vector3D(x - lx/2, y - ly/2,z - lz/2);

    //8th vertex
    Vector3D Botrightback = Vector3D(x - lx/2, y - ly/2,z + lz/2);

    Polygone Topface = Polygone(Topleftback, Topleftfront, Toprightfront, Toprightback);
    Polygone Botface = Polygone(Botleftback, Botleftfront, Botrightfront, Botrightback);
    Polygone Rightface = Polygone(Toprightback, Toprightfront, Botrightfront, Botrightback);
    Polygone Leftface = Polygone(Topleftback, Topleftfront, Botleftfront, Botleftback);
    Polygone Frontface = Polygone(Topleftfront, Toprightfront, Botrightfront, Botleftfront);
    Polygone Backface = Polygone(Topleftback, Toprightback, Botrightback, Botleftback);

    polygones.push_back(Topface);
    polygones.push_back(Botface);
    polygones.push_back(Rightface);
    polygones.push_back(Leftface);
    polygones.push_back(Frontface);
    polygones.push_back(Backface);

    return polygones;
}

void gamegui4::DrawPolygone(Polygone polygone, int id)
{
    Matrix* orientationMat = new Matrix(3);
    orientationMat->SetOrientation(*pactorList->getActor(id)->getRigidbody()->getOrientation());
    Vector3D* translationVec = pactorList->getActor(id)->getRigidbody()->getPosition();


    std::vector<float> * tab = new std::vector<float>();
    for(int i=0;i<16;i++)
    {
      int line =(int)i/4;
      int col = i%4;
      if(col<3&&line<3)
      {
        tab->push_back((*orientationMat)(line,col));
      }
      else if(col==3&&line<3)
      {
        tab->push_back((*translationVec)[line]);
      }
      else if(col<3&&line==3)
      {
        tab->push_back(0);
      }
      else { tab->push_back(1); }
    }
    Matrix* transformMatrix= new Matrix(4,tab->data());

    GLfloat* m = new float[16];
    m[0] = transformMatrix->operator()(0,0);
    m[1] = transformMatrix->operator()(1,0);
    m[2] = transformMatrix->operator()(2,0);
    m[3] = transformMatrix->operator()(3,0);
    m[4] = transformMatrix->operator()(0,1);
    m[5] = transformMatrix->operator()(1,1);
    m[6] = transformMatrix->operator()(2,1);
    m[7] = transformMatrix->operator()(3,1);
    m[8] = transformMatrix->operator()(0,2);
    m[9] = transformMatrix->operator()(1,2);
    m[10] = transformMatrix->operator()(2,2);
    m[11] = transformMatrix->operator()(3,2);
    m[12] = transformMatrix->operator()(0,3);
    m[13] = transformMatrix->operator()(1,3);
    m[14] = transformMatrix->operator()(2,3);
    m[15] = transformMatrix->operator()(3,3);

    //for(int i=0;i<16;i++){
    //std::cout<<m[i]<<std::endl;}

    glPushMatrix();
//    float angle = qRadiansToDegrees(2*qAcos(pactorList->getActor(id)->getRigidbody()->getOrientation()->getW()));
//    float rx = qRadiansToDegrees(2*qAsin(pactorList->getActor(id)->getRigidbody()->getOrientation()->getI()));
//    float ry = qRadiansToDegrees(2*qAsin(pactorList->getActor(id)->getRigidbody()->getOrientation()->getJ()));
//    float rz = qRadiansToDegrees(2*qAsin(pactorList->getActor(id)->getRigidbody()->getOrientation()->getK()));
    glMultMatrixf(m);

   // glTranslatef(pactorList->getActor(id)->getRigidbody()->getPosition()->getX(),pactorList->getActor(id)->getRigidbody()->getPosition()->getY(),
   //              pactorList->getActor(id)->getRigidbody()->getPosition()->getZ());


   if (id == 0){
        GLfloat colorAmbientBl_tab[] = {0.25,0.25,0.5,1.0};
        glMaterialfv(GL_FRONT, GL_AMBIENT, colorAmbientBl_tab);
        GLfloat colorDiffuseBl_tab[] = {0.5,0.5,1.0,0.0};
        glMaterialfv(GL_FRONT, GL_DIFFUSE, colorDiffuseBl_tab);
        GLfloat colorSpecularBl_tab[] = {0.0,0.0,0.0,0.0};
        glMaterialfv(GL_FRONT, GL_SPECULAR, colorSpecularBl_tab);
    }

    if (id == 1){
        GLfloat colorAmbient_tab[] = {0.24725f,0.1995f,0.0745f,0.4};
        glMaterialfv(GL_FRONT, GL_AMBIENT, colorAmbient_tab);
        GLfloat colorDiffuse_tab[] = {0.75164f,0.60648f,0.22648f,0.4};
        glMaterialfv(GL_FRONT, GL_DIFFUSE, colorDiffuse_tab);
        GLfloat colorSpecular_tab[] = {0.628281,0.555802,0.366065,0.4};
        glMaterialfv(GL_FRONT, GL_SPECULAR, colorSpecular_tab);
        glMaterialf(GL_FRONT, GL_SHININESS, 76.f);
    }

    if (id == 2){
        GLfloat colorAmbient_tab[] = {0.19125, 0.0735, 0.0225, 0.1};
        glMaterialfv(GL_FRONT, GL_AMBIENT, colorAmbient_tab);
        GLfloat colorDiffuse_tab[] = {0.7038, 0.27048,	0.0828,0.1};
        glMaterialfv(GL_FRONT, GL_DIFFUSE, colorDiffuse_tab);
        GLfloat colorSpecular_tab[] = {0.256777, 0.137622, 0.086014, 0.1};
        glMaterialfv(GL_FRONT, GL_SPECULAR, colorSpecular_tab);
        glMaterialf(GL_FRONT, GL_SHININESS, 76.f);
    }

    if (id == 3){
        GLfloat colorAmbient_tab[] = {0.25, 0.25, 0.25,0.6};
        glMaterialfv(GL_FRONT, GL_AMBIENT, colorAmbient_tab);
        GLfloat colorDiffuse_tab[] = {0.4, 0.4,	0.4, 0.6};
        glMaterialfv(GL_FRONT, GL_DIFFUSE, colorDiffuse_tab);
        GLfloat colorSpecular_tab[] = {0.774597, 0.774597, 0.774597,0.6};
        glMaterialfv(GL_FRONT, GL_SPECULAR, colorSpecular_tab);
        glMaterialf(GL_FRONT, GL_SHININESS, 76.f);
    }

    glBegin(GL_QUADS);

    glVertex3f(polygone.s0.getX(),polygone.s0.getY(),polygone.s0.getZ());
    glVertex3f(polygone.s1.getX(),polygone.s1.getY(),polygone.s1.getZ());
    glVertex3f(polygone.s2.getX(),polygone.s2.getY(),polygone.s2.getZ());
    glVertex3f(polygone.s3.getX(),polygone.s3.getY(),polygone.s3.getZ());


    glEnd();

    glPopMatrix();
}

void gamegui4::demo1()
{
    int i = 0;
    int ind = 0;
    int size = pactorList->size();
    while(i < size){
        Actors* act = pactorList->getActor(ind);
        if(act!=nullptr)
        {
            pactorList->removeActor(ind);
            i++;
        }
        ind++;
    }

    float valueDiagCuboidX = float(1)/float(12)*float(100)*float(800);
    float valueDiagCuboidY = float(1)/float(12)*float(100)*float(800);
    float valueDiagCuboidZ = float(1)/float(12)*float(100)*float(800);
    float cuboidInertia[9] = {valueDiagCuboidX,0,0,0,valueDiagCuboidY,0,0,0,valueDiagCuboidZ};

    Matrix * inertiaInitializer = new Matrix(3,cuboidInertia);
    Rigidbody bodyInitializer = Rigidbody(0,0,0,100,new Quaternion(1,0,0,0),inertiaInitializer);
    std::vector<Polygone> polygonesInitializer = CreateCubePolygone(0,0,0,1,1,1);
    Actors actorInitializer = Actors(bodyInitializer, polygonesInitializer, 0, true);

    pactorList->addActor(actorInitializer);
    delete inertiaInitializer;

    valueDiagCuboidX = float(1)/float(12)*float(200)*float(325);
    valueDiagCuboidY = float(1)/float(12)*float(200)*float(1000);
    valueDiagCuboidZ = float(1)/float(12)*float(200)*float(1125);
    float cuboidInertia2[9] = {valueDiagCuboidX,0,0,0,valueDiagCuboidY,0,0,0,valueDiagCuboidZ};

    inertiaInitializer = new Matrix(3,cuboidInertia2);

    bodyInitializer = Rigidbody(-100,-5,0,200,new Quaternion(1,0,0,0),inertiaInitializer);
    polygonesInitializer = CreateCubePolygone(0,0,0,10,10,10);
    actorInitializer = Actors(bodyInitializer, polygonesInitializer, 1, false);

    pactorList->addActor(actorInitializer);
    delete inertiaInitializer;
}
