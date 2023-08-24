#include <iostream>
#include <math.h>

class MotorizedVehicle{
    public:
        virtual void display(){std::cout<<"I am an MV\n";}
        void throttle(){std::cout<<"speeds up\n";}
        virtual void refuel(){std::cout<<"refueling\n";}
        virtual void brake(){std::cout<<"slows down\n";}
};

class GasPowered : public MotorizedVehicle {
    public:
        void display(){std::cout<<"I run on gas\n";}
};

class Hyrid : public MotorizedVehicle {
    public:
        void display(){std::cout<<"I am a hyrid\n";}
        void brake(){std::cout<<"battery charges as car slows\n";}
};

class Electric : public MotorizedVehicle {
    public:
        void display(){std::cout<<"I am EV\n";}
        void refuel(){std::cout<<"EV is charging\n";}
        void brake(){std::cout<<"battery charges as car slows\n";}
};

class Shape2D{
    public:
        float width;
        float height;
        virtual float getArea() = 0;
};

class Triangle : public Shape2D {
    public:
        Triangle(float w,float h){
            height = h;
            width = w;
        }
        float getArea(){
            return width*height*float(0.5);
        }
};

class Rectangle : public Shape2D {
    public:
        Rectangle(float w,float h){
            height = h;
            width = w;
        }
        float getArea(){
            return height * width;
        }
};

class Circle : public Shape2D {
    public:
        Circle(float r){
            height = r;
            width = r;
        }
        float getArea(){
            return height * width * float(M_PI); 
        }
};

int main(){
    MotorizedVehicle* mv = new Electric();
    mv -> display();
    mv -> refuel();
    mv -> throttle();
    mv -> brake();
    delete mv;
    //Shape2D* s = new Shape2D();
    Shape2D* t = new Triangle(2.0,3.0);
    std::cout<<"Triangle area "<<t-> getArea()<<"\n";

    delete t;
    return 0;


}
