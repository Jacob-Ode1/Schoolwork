#include <iostream>
using namespace std;

class State{
    protected:
        float tax;
    public:
        float getTax(){return tax;}
        State(){
            tax = 0.0;
        }
        State(float t){
            tax = t;
        }
};

class Duck{
    protected: 
        float cost;
        State* state;
    public:
        float getCost(){return cost;}
        float getTotalCost(){return cost + cost* state->getTax();}
        float getTax(){return state->getTax();}
        ~Duck(){
            delete state;
        }
};

class Mallard : public Duck {
    public:
        Mallard(){
            cost = 12.61;
            state = new State();
        }
        Mallard(State s){
            cost = 12.61;
            state = new State(s.getTax());
        }
};

class WoodDuck : public Duck {
    public:
        WoodDuck(){
            cost = 150.00;
            state = new State();
        }
        WoodDuck(State s){
            cost = 150.00;
            state = new State(s.getTax());
        }
};

class Rubber : public Duck {
    public:
        Rubber(){
            cost = .01;
            state = new State();
        }
        Rubber(State s){
            cost = .01;
            state = new State(s.getTax());
        }
};

class StateFactory {
    protected:
        State* state;
    public:
        StateFactory(){
            state = new State();
        }
        StateFactory(State s){
            state = new State(s.getTax());
        }
        Mallard* createMallard(){
            return new Mallard(*state);
        }
        WoodDuck* createWoodDuck(){
            return new WoodDuck(*state);
        }
        Rubber* createRubber(){
            return new Rubber(*state);
        }
        ~StateFactory(){
            delete state;
        }
};

class Facade {
    private:
        StateFactory* MNFactory;
        StateFactory* CAFactory;
        StateFactory* NYFactory;
        string state;
        string type;
    public:
        Facade(){
            State MN = State(.06875);
            State CA = State(.0725);
            State NY = State(.045);
            MNFactory = new StateFactory(MN);
            CAFactory = new StateFactory(CA);
            NYFactory = new StateFactory(NY);
            state = "";
            type = "";
        }
        ~Facade(){
            delete MNFactory;
            delete CAFactory;
            delete NYFactory;
        }
        void run(){
            query();
            Duck* d = createDuck();
            cout<<"The cost of a "<<type<<" in "<<state<<" is "<<d->getTotalCost()<<".\n";
            delete d;
        }
        void query(){
            cout<<"What state?\n";
            cin>>state;
            while(!(state == "MN" || state == "CA" || state == "NY")){
                cout<<"Invalid state, try again please\n";
                cin>>state;
            }
            cout<<"What type of duck?\n";
            cin>>type;
            while(!(type == "Mallard" || type == "WoodDuck" || type == "Rubber")){
                cout<<"Invalid duck type, try again please\n";
                cin>>type;
            }
        }
        Duck* createDuck(){
            if(state=="MN"){
                if(type=="Mallard"){
                    return MNFactory->createMallard();
                }
                if(type=="WoodDuck"){
                    return MNFactory->createWoodDuck();
                }
                if(type=="Rubber"){
                    return MNFactory->createRubber();
                }
            }
            else if(state=="CA"){
                if(type=="Mallard"){
                    return CAFactory->createMallard();
                }
                if(type=="WoodDuck"){
                    return CAFactory->createWoodDuck();
                }
                if(type=="Rubber"){
                    return CAFactory->createRubber();
                }
            }
            else if(state=="NY"){
                if(type=="Mallard"){
                    return NYFactory->createMallard();
                }
                if(type=="WoodDuck"){
                    return NYFactory->createWoodDuck();
                }
                if(type=="Rubber"){
                    return NYFactory->createRubber();
                }
            }
            else {
                cout<<"Please call the query function first.\n";
            }
            return NULL;
        }
};

int main(){
    Facade* f = new Facade();
    f->run();
    delete f;
    return 0;
}