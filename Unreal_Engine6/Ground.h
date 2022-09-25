#include <qopengl.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <QColor>
#include <QRandomGenerator>

// Classe dediee pour la gestion du sol
class Ground
{
    GLUquadric* quadrique;
public:
    // Constructeur avec parametres
    Ground();

    void sendTextures(GLuint* text);

    void slideSky();

    // Destructeur
    ~Ground();

    // Methode d'affichage
    void Display() const;

    float getPosTarget(){return posTarget;}

    void moveTarget();

private:
    GLuint* textures;
    float posRoad;
    float posCiel;
    float posTarget;
    QRandomGenerator* random;
};