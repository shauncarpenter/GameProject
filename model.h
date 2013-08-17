//A data structure encapsulating an entire object
typedef struct Object{
  Vector3 position;
  Matrix model_mat;
  Mesh* mesh;
} Object;

void move_object(Object* object, float x, float y, float z);
void move_object(Object* object, float* array); //Possibly faster.

void set_location(Object* object, float x, float y, float z);
void set_location(Object* object, float* array); //Possibly faster.

//All amounts are in radians.
void set_yaw(Object* object, float amount); //Rotate around Z.
void set_pitch(Object* object, float amount); //Rotate around X.
void set_roll(Object* object, float amount); //Rotate around Y.
