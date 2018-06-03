#include <iostream>
#include <string>
using namespace std;

class Operation 
{ 
    public: 
        Operation ():_numberA(0), _numberB(0){}; 
        Operation (double numA, double numB):
            _numberA(numA), _numberB(numB) {}; 
        virtual ~Operation (){}; 


        double GetNumberA(){
            return _numberA;
        };
        void SetNumberA(double numA){
            _numberA = numA;
        };
        
        double GetNumberB(){
            return _numberB;
        };
        void SetNumberB(double numB){
            _numberB = numB;
        };

        virtual double GetResult(){
            double result = 0;
            return result;
        }; 
        // virtual double GetResult() = 0;

    private: 
        double _numberA;
        double _numberB;

}; 

class OperationAdd : public Operation
{ 
    public: 
        OperationAdd (){};
        virtual ~OperationAdd (){};
        virtual double GetResult(){
            double result = 0;
            result = GetNumberA() + GetNumberB();
            return result;
        };

    private: 
}; 

class OperationFactory 
{ 
    public: 
        OperationFactory (){
            opeartion = NULL;
        }; 
        virtual ~OperationFactory (){
            delete opeartion;
        }; 
        Operation * createOperate(char opearte);

    private:
        Operation *opeartion;
}; 

Operation * OperationFactory::createOperate(char opearte){
    switch (opearte) { 
        case '+': {
            opeartion = new OperationAdd(); 
            break; 
        } 
        case '-': { 
            break; 
        } 
        default: { 
            break; 
        } 
    } 
    return opeartion;
} 

int main(int argc, const char *argv[])
{
    Operation oper1(2, 4);
    // Operation* oper = &oper1;
    Operation* oper;
    OperationFactory factory;
    try { 
        oper = factory.createOperate('+');
    } catch (exception &e) {
        cout<<e.what()<<endl;
        exit(1);
    } 
    oper->SetNumberA(1);
    oper->SetNumberB(4);
    double result = oper->GetResult();
    cout << "result: " << result << endl;

    return 0;
}


