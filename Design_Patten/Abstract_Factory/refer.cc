#include<string>
#include<iostream>


//数据库表项：User  与工厂模式无关
class User
{
private:
    int id;
    std::string name;
public:
    int getID()
    {
        return id;
    }
    std::string getName()
    {
        return name;
    }
    void setID(int ID)
    {
        this->id = ID;
    }
    void setName(std::string NAME)
    {
        this->name = NAME;
    }
};


//数据库表项：Department 与工厂模式无关
class Department
{
private:
    int id;
    std::string name;
public:
    int getID()
    {
        return id;
    }
    std::string getName()
    {
        return name;
    }
    void setID(int ID)
    {
        this->id = ID;
    }
    void setName(std::string NAME)
    {
        this->name = NAME;
    }
};




//抽象产品A:IUser
class AbstractProductA{
public:
    virtual void  Insert(User user) = 0;
    virtual User* GetUser(int id) = 0;

    virtual ~AbstractProductA() {}
};

//具体产品A1 SqlProductA
class SqlProductA :public AbstractProductA{
public:
    void  Insert(User user){
        std::cout << "在SQL Server中给User表增加了一条记录" << std::endl;
    }
    User*  GetUser(int id){
        std::cout << "在SQL Server中得到id为:"<<id<<" User表一条记录" << std::endl;
        return NULL;
    }
};
//具体产品A2 AccessProductA
class AccessProductA :public AbstractProductA{
public:
    void  Insert(User user){
        std::cout << "在Access中给User表增加了一条记录" << std::endl;
    }
    User*  GetUser(int id){
        std::cout << "在Access中得到id为:" << id << " User表一条记录" << std::endl;
        return NULL;
    }
};

//抽象产品B：IDepartment
class AbstractProductB{
public:
    virtual void  Insert(Department department) = 0;
    virtual  Department* GetDepartment(int id) = 0;
    
    virtual ~AbstractProductB() {}
};


//具体产品B1 SqlProductB
class SqlProductB :public AbstractProductB{
public:
    void  Insert(Department department){
        std::cout << "在SQL Server中给department表增加了一条记录" << std::endl;
    }
    Department* GetDepartment(int id){
        std::cout << "在SQL Server中得到id为:" << id << " Department表一条记录" << std::endl;
        return NULL;
    }
};


//具体产品B2 AccessProductB
class AccessProductB :public AbstractProductB{
public:
    void  Insert(Department department){
        std::cout << "在Access中给department表增加了一条记录" << std::endl;
    }
    Department*  GetDepartment(int id){
        std::cout << "在Access中得到id为:" << id << " Department表一条记录" << std::endl;
        return NULL;
    }
};


class AbstractFactory{
public:
    virtual AbstractProductA* createProductA() = 0;
    virtual AbstractProductB* createProductB() = 0;
    virtual ~AbstractFactory(){}
};

//具体工厂1：SqlServerFactory
class SqlFactory :public AbstractFactory
{
public:
    AbstractProductA* createProductA()
    {
        return new SqlProductA;
    }
    AbstractProductB* createProductB()
    {
        return new SqlProductB;
    }
};

//具体工厂2：AccessFactory
class AccessFactory :public AbstractFactory{
public:
    AbstractProductA* createProductA()
    {
        return new AccessProductA;
    }
    AbstractProductB* createProductB()
    {
        return new AccessProductB;

    }
};


int main()
{
    //初始化数据库
    User user;
    Department department;

    //ConcreteFactory1
    AbstractFactory* factory = NULL;
    //factory = new SqlFactory;
    factory = new AccessFactory;
    //ProductA1
    AbstractProductA* iu = NULL;
    iu = factory->createProductA();
    iu->Insert(user);
    iu->GetUser(1);

    //ProductB1
    AbstractProductB* id = NULL;
    id = factory->createProductB();
    id->Insert(department);
    id->GetDepartment(1);

    if (factory != NULL)
    {
        delete factory;
        factory = NULL;
    }
    if (iu != NULL)
    {
        delete iu;
        iu = NULL;
    }
    if (id != NULL)
    {
        delete id;
        id = NULL;
    }

    /* system("pause"); */

}
