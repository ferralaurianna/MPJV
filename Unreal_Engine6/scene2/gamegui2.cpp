#include "gamegui2.h"

const float PI=3.14159;


GameGUI2::GameGUI2(QWidget *parent): QOpenGLWidget(parent)
{
    // Initialize the instance of the objects to render at the first rendering (blob, timer, ...)
    score = 0;
    scoreBase=0;
    Blob* b = new Blob(0,0,0,10,5,4);
    blobs_.push_back(b);
    gameTimer = new GameTimer2();
    gameTimer->startGameTimer(9999);
}

GameGUI2::~GameGUI2()
{
    // Manage the memory leak caused by the Particle vector
    for(Blob* blob : blobs_)
    {
        delete blob;
    }
    delete Pdepart;
    delete Piece1;
    delete Pique1;
}

// Initialize OpenGL parameters before the first rendering
void GameGUI2::initializeGL()
{

    Pdepart = new Plateforme(70,150,10,0,-30,0);
    Piece1 = new Coin(20,4,-40,0,0);
    Pique1 = new Spike(20,50,0,0);

    volumes.push_back(Pdepart->getPolygones());
    volumes.push_back(Piece1->getPolygones());
    volumes.push_back(Pique1->getPolygones());

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

    // Loading of textures
    //QImage texGrass = QImage(":/grass.jpg").convertToFormat(QImage::Format_RGBA8888);

    // Storage of the scene's textures in a table
    //texturesScene = new GLuint[3];

    /*glGenTextures(3,texturesScene);
    glBindTexture(GL_TEXTURE_2D,texturesScene[0]);
    glTexImage2D(GL_TEXTURE_2D, 0, 4,texGrass.width(),texGrass.height(),0,GL_RGBA,GL_UNSIGNED_BYTE,texGrass.bits());
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_T,GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_S,GL_REPEAT);*/

    // Sending the table to the scene
    //scene->sendTextures(texturesScene);

    resizeGL(width(),height());

    connect(gameTimer, SIGNAL(blobShrinkSignal()), this, SLOT(shrink()) );
}



void GameGUI2::resizeGL(int width, int height)
{
    // Viewport definition
    glViewport(0, 0, width, height);
}


// General rendering management
void GameGUI2::paintGL()
{
    // Clear background
    glClearColor(background.redF(),background.greenF(),background.blueF(),background.alphaF());
    // Clear depth
    glClear(GL_DEPTH_BUFFER_BIT|GL_COLOR_BUFFER_BIT);

    glEnable(GL_DEPTH_TEST);

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

    // Where to put the render methods to render object on the screen
    //scene->Display();
    for(Blob* blob : blobs_)
    {
        blob->display();
    }
    //scene->slideSky();

    //Test
    Pdepart->Display();
    Piece1->Display();
    Pique1->Display();

    glDisable(GL_DEPTH_TEST);

    // Paint timer
    gameTimer->drawGameTimer(this);
}



// Camera controls
void GameGUI2::forwardCamera() {
    cameraX_ += cos(angleCamera_*PI/180);
    cameraZ_ -= sin(angleCamera_*PI/180);
    centralX_ += cos(angleCamera_*PI/180);
    centralZ_ -= sin(angleCamera_*PI/180);
}
void GameGUI2::backwardCamera() {
    cameraX_ -= cos(angleCamera_*PI/180);
    cameraZ_ += sin(angleCamera_*PI/180);
    centralX_ -= cos(angleCamera_*PI/180);
    centralZ_ += sin(angleCamera_*PI/180);
}
void GameGUI2::turnRightCamera() {
    angleCamera_ += 5;
    if (angleCamera_ > 360) {
        angleCamera_ -= 360;
    }
    cameraX_ = centralX_ - distanceCamera_*cos((angleCamera_)*PI/180);
    cameraZ_ = centralZ_ + distanceCamera_*sin((angleCamera_)*PI/180);
}
void GameGUI2::turnLeftCamera() {
    angleCamera_ -= 5;
    if (angleCamera_ < 0) {
        angleCamera_ += 360;
    }
    cameraX_ = centralX_ - distanceCamera_*cos((angleCamera_)*PI/180);
    cameraZ_ = centralZ_ + distanceCamera_*sin((angleCamera_)*PI/180);
}
void GameGUI2::zoomIn() {
    cameraX_ -= cos(angleCamera_*PI/180);
    cameraZ_ += sin(angleCamera_*PI/180);
    distanceCamera_+=1;
}
void GameGUI2::zoomOut() {
    cameraX_ += cos(angleCamera_*PI/180);
    cameraZ_ -= sin(angleCamera_*PI/180);
    distanceCamera_-=1;
}
void GameGUI2::goUp() {
    cameraY_+=1;
    centralY_+=1;
}
void GameGUI2::goDown() {
    cameraY_-=1;
    centralY_-=1;
}

void GameGUI2::shrink() {
    for(Blob* b : blobs_)
    {
        if(!b->shrinkBlob()) { // End game condition
            emit gameEndedSignal();
            return;
        }
    }
}
