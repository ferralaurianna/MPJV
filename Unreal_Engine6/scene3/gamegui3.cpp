#include "gamegui3.h"

const float PI=3.14159;


GameGUI3::GameGUI3(QWidget *parent): QOpenGLWidget(parent)
{
    // Initialize the instance of the objects to render at the first rendering (gun, ground...)
}

GameGUI3::~GameGUI3()
{

}


// Initialize OpenGL parameters before the first rendering
void GameGUI3::initializeGL()
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



void GameGUI3::resizeGL(int width, int height)
{
    // Viewport definition
    glViewport(0, 0, width, height);
}


// General rendering management
void GameGUI3::paintGL()
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
    while(i < pactorList->size()){
        Actors* act = pactorList->getActor(i);
        if(act!=nullptr)
        {
            for( Polygone pol : *(act->getPolygones()))
            {
                DrawPolygone(pol,i);
            }
            i++;
        }
    }

}

void GameGUI3::setactorList(ActorList* actorlist_) {
    pactorList = actorlist_;

    //100 est la masse
    float valueDiagCuboid = float(1)/float(12)*float(100)*float(2);
    float cuboidInertia[16] = {valueDiagCuboid,0,0,0,0,valueDiagCuboid,0,0,0,0,valueDiagCuboid,0,0,0,0,1};

    Matrix * inertiaInitializer = new Matrix(4,cuboidInertia);

    Rigidbody bodyInitializer = Rigidbody(0,0,0,100,new Quaternion(1,0,0,0),inertiaInitializer);
    std::vector<Polygone> polygonesInitializer = CreateCubePolygone(0,0,0,400,1,400);
    Actors actorInitializer = Actors(bodyInitializer, polygonesInitializer, 0, false);

    pactorList->addActor(actorInitializer);

    bodyInitializer = Rigidbody(0,10,0,10,new Quaternion(0,1,0,0),inertiaInitializer);
    polygonesInitializer = CreateCubePolygone(0,0,0,10,10,20);
    actorInitializer = Actors(bodyInitializer,polygonesInitializer, 1);

    pactorList->addActor(actorInitializer);

    bodyInitializer = Rigidbody(0,10,-50,10,new Quaternion(1,0,0,0),inertiaInitializer);
    polygonesInitializer = CreateCubePolygone(0,0,0,10,10,20);
    actorInitializer = Actors(bodyInitializer,polygonesInitializer, 2);

    pactorList->addActor(actorInitializer);

    bodyInitializer = Rigidbody(40,10,-30,10,new Quaternion(1,0,0,0),inertiaInitializer);
    polygonesInitializer = CreateOddPolygone(0,0,0,15,10,15);
    actorInitializer = Actors(bodyInitializer,polygonesInitializer, 3);

    pactorList->addActor(actorInitializer);
}



// Camera controls
void GameGUI3::forwardCamera() {
    cameraX_ += cos(angleCamera_*PI/180);
    cameraZ_ -= sin(angleCamera_*PI/180);
    centralX_ += cos(angleCamera_*PI/180);
    centralZ_ -= sin(angleCamera_*PI/180);
}
void GameGUI3::backwardCamera() {
    cameraX_ -= cos(angleCamera_*PI/180);
    cameraZ_ += sin(angleCamera_*PI/180);
    centralX_ -= cos(angleCamera_*PI/180);
    centralZ_ += sin(angleCamera_*PI/180);
}
void GameGUI3::turnRightCamera() {
    angleCamera_ += 5;
    if (angleCamera_ > 360) {
        angleCamera_ -= 360;
    }
    cameraX_ = centralX_ - distanceCamera_*cos((angleCamera_)*PI/180);
    cameraZ_ = centralZ_ + distanceCamera_*sin((angleCamera_)*PI/180);
}
void GameGUI3::turnLeftCamera() {
    angleCamera_ -= 5;
    if (angleCamera_ < 0) {
        angleCamera_ += 360;
    }
    cameraX_ = centralX_ - distanceCamera_*cos((angleCamera_)*PI/180);
    cameraZ_ = centralZ_ + distanceCamera_*sin((angleCamera_)*PI/180);
}
void GameGUI3::zoomIn() {
    cameraX_ -= cos(angleCamera_*PI/180);
    cameraZ_ += sin(angleCamera_*PI/180);
    distanceCamera_+=1;
}
void GameGUI3::zoomOut() {
    cameraX_ += cos(angleCamera_*PI/180);
    cameraZ_ -= sin(angleCamera_*PI/180);
    distanceCamera_-=1;
}
void GameGUI3::goUp() {
    cameraY_+=1;
    centralY_+=1;
}
void GameGUI3::goDown() {
    cameraY_-=1;
    centralY_-=1;
}

std::vector<Polygone> GameGUI3::CreateCubePolygone(float x,float y,float z,float lx,float ly,float lz){

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

std::vector<Polygone> GameGUI3::CreateOddPolygone(float x,float y,float z,float lx,float ly,float lz){

    std::vector<Polygone> polygones;

    //1st vertex
    Vector3D Topleftback = Vector3D(x + lx/2, y + ly/2,z + lz/2);

    //2nd vertex
    Vector3D Topleftfront = Vector3D(x + lx/2, y + ly/2,z - lz/2);

    //3rd vertex
    Vector3D TopMiddlefront = Vector3D(x, y + ly/2,z - lz/2);

    //4th vertex
    Vector3D TopMiddleMiddle = Vector3D(x, y + ly/2,z);

    //5th vertex
    Vector3D TopMiddleright = Vector3D(x - lx/2, y + ly/2,z);

    //6th vertex
    Vector3D Toprightback = Vector3D(x - lx/2, y + ly/2,z + lz/2);

    //7th vertex
    Vector3D Botleftback = Vector3D(x + lx/2, y - ly/2,z + lz/2);

    //8th vertex
    Vector3D Botleftfront = Vector3D(x + lx/2, y - ly/2,z - lz/2);

    //9th vertex
    Vector3D BotMiddlefront = Vector3D(x, y - ly/2,z - lz/2);

    //10th vertex
    Vector3D BotMiddleMiddle = Vector3D(x, y - ly/2,z);

    //11th vertex
    Vector3D BotMiddleright = Vector3D(x - lx/2, y - ly/2,z);

    //6th vertex
    Vector3D Botrightback = Vector3D(x - lx/2, y - ly/2,z + lz/2);

    Polygone Topleftface = Polygone(Topleftback, Topleftfront, TopMiddlefront, TopMiddleMiddle);
    Polygone Toprightface = Polygone(Topleftback, TopMiddleMiddle, TopMiddleright, Toprightback);
    Polygone Botleftface = Polygone(Botleftback, Botleftfront, BotMiddlefront, BotMiddleMiddle);
    Polygone Botrightface = Polygone(Botleftback, BotMiddleMiddle, BotMiddleright, Botrightback);
    Polygone Rightface = Polygone(Toprightback, TopMiddleright, BotMiddleright, Botrightback);
    Polygone Leftface = Polygone(Topleftback, Topleftfront, Botleftfront, Botleftback);
    Polygone Frontface = Polygone(Topleftfront, TopMiddlefront, BotMiddlefront, Botleftfront);
    Polygone Backface = Polygone(Topleftback, Toprightback, Botrightback, Botleftback);
    Polygone Inwardfrontface = Polygone(TopMiddleMiddle,TopMiddleright,BotMiddleright,BotMiddleMiddle);
    Polygone Inwardsideface = Polygone(TopMiddleMiddle,TopMiddlefront,BotMiddlefront,BotMiddleMiddle);

    polygones.push_back(Topleftface);
    polygones.push_back(Toprightface);
    polygones.push_back(Botleftface);
    polygones.push_back(Botrightface);
    polygones.push_back(Rightface);
    polygones.push_back(Leftface);
    polygones.push_back(Frontface);
    polygones.push_back(Backface);
    polygones.push_back(Inwardfrontface);
    polygones.push_back(Inwardsideface);

    return polygones;
}

void GameGUI3::DrawPolygone(Polygone polygone, int id)
{
    Matrix* orientation = new Matrix(3);
    orientation->SetOrientation(*pactorList->getActor(id)->getRigidbody()->getOrientation());
    GLfloat* m = new float[8];
    m[0] = orientation->operator()(0,0);
    m[1] = orientation->operator()(0,1);
    m[2] = orientation->operator()(0,2);
    m[3] = orientation->operator()(1,0);
    m[4] = orientation->operator()(1,1);
    m[5] = orientation->operator()(1,2);
    m[6] = orientation->operator()(2,0);
    m[7] = orientation->operator()(2,1);
    m[8] = orientation->operator()(2,2);


    glPushMatrix();
//    float angle = qRadiansToDegrees(2*qAcos(pactorList->getActor(id)->getRigidbody()->getOrientation()->getW()));
//    float rx = qRadiansToDegrees(2*qAsin(pactorList->getActor(id)->getRigidbody()->getOrientation()->getI()));
//    float ry = qRadiansToDegrees(2*qAsin(pactorList->getActor(id)->getRigidbody()->getOrientation()->getJ()));
//    float rz = qRadiansToDegrees(2*qAsin(pactorList->getActor(id)->getRigidbody()->getOrientation()->getK()));
    glMultMatrixf(m);

    glTranslatef(pactorList->getActor(id)->getRigidbody()->getPosition()->getX(),pactorList->getActor(id)->getRigidbody()->getPosition()->getY(),
                 pactorList->getActor(id)->getRigidbody()->getPosition()->getZ());


    glBegin(GL_QUADS);

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

    glVertex3f(polygone.s0.getX(),polygone.s0.getY(),polygone.s0.getZ());
    glVertex3f(polygone.s1.getX(),polygone.s1.getY(),polygone.s1.getZ());
    glVertex3f(polygone.s2.getX(),polygone.s2.getY(),polygone.s2.getZ());
    glVertex3f(polygone.s3.getX(),polygone.s3.getY(),polygone.s3.getZ());


    glEnd();

    glPopMatrix();
}
