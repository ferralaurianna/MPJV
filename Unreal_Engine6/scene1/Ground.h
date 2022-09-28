#include <qopengl.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <QColor>
#include <QRandomGenerator>

/**
 * @brief The Ground class
 * Ground handle the background of the 3D scene.
 */
class Ground
{
public:
    /**
     * @brief Ground
     * The constructor of the Ground class.
     */
    Ground();
    /**
     * @brief sendTextures
     * @param text
     * sendTextures is used to pass the pointer to a texture matrix to a gun object.
     */
    void sendTextures(GLuint* text);
    /**
     * @brief slideSky
     *This function is to be called is frame to move the sky's texture.
     */
    void slideSky();
    /**
     * @brief ~Ground
     * The destructor of the Ground class.
     */
    ~Ground();
    /**
     * @brief Display
     * Display is called to draw the background in the scene.
     */
    void Display() const;

    float getPosTarget(){return posTarget;}
    /**
     * @brief Display
     * Randomize the posing of the target between 0 and 200.
     */
    void moveTarget();

private:
    /**
     * @brief quadrique
     * A pointer to an instance of GLUquadric necessary to draw quadrics.
     */
    GLUquadric* quadrique;
    /**
     * @brief textures
     * A pointer to the texure matrix used to texture the gun.
     */
    GLuint* textures;

    /**
     * @brief posSky, posTarget
     * Floats that register the current positions of the moving sky texture and target.
     */
    float posSky;
    float posTarget;

    /**
     * @brief textures
     * A pointer to the random generator used to move the target.
     */
    QRandomGenerator* random;
};
