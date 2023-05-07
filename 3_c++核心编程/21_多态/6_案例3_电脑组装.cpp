//
// Created by NUC on 2023/5/4.
//

#include<string>
#include<iostream>

using namespace std; // 这是个不好的习惯

// 抽象每个零件的类: 作为基准
class CPU{
public:
    virtual void calculate() = 0;
};

// 显卡: GPU
class VideoCard{
public:
    virtual void display() = 0;
};
// 内存
class Memory{
public:
    virtual void storage() = 0;
};

// 电脑类:
class Computer{
public:
    // 构造函数传入三个零件指针.
    Computer(CPU *cpu, VideoCard *videoCard, Memory *memory){ // 多态的概念, 父类的指针.  传进来的是子类的对象
        this->cpu = cpu; // 调用不同的子类的对象的函数.
        this->videoCard = videoCard;
        this->memory = memory;
    }

    ~Computer(){ // 提供一个析构函数, 释放三个电脑零件
        cout << " ~Computer()" << endl;
        if (this->cpu){
            delete this->cpu;
            this->cpu = NULL;
        }
        if (this->videoCard){
            delete this->videoCard;
            this->videoCard = NULL;
        }
        if (this->memory){
            delete this->memory;
            this->memory = NULL;
        }
    }

    void work(){ // 工作的函数.
        this->cpu->calculate();
        this->videoCard->display();
        this->memory->storage();
    }


private:
    CPU* cpu = NULL; // CPU零件的指针
    VideoCard *videoCard = NULL;
    Memory *memory = NULL;
};

// 不同电脑厂家实现的类别:
class IntelCPU: public CPU{
public:
    void calculate(){
        cout << "intel的cpu开始计算了" << endl;
    }
};

class NvidiaGPU: public VideoCard{
public:
    void display(){
        cout << "Nvidia的GPU开始工作了" << endl;
    }
};

class LenovoMemory: public Memory{
public:
    void storage(){
        cout << "Lenovo的内存条开始工作了" << endl;
    }
};

void test01(){
    CPU *cpu = new IntelCPU(); // 父类指针接收子类对象
    VideoCard *gpu = new NvidiaGPU();
    Memory *memory = new LenovoMemory();

    Computer *computer = new Computer(cpu, gpu, memory);
    computer->work();

    delete computer; // 执行析构函数.
}




int main() {
    test01();






    return 0;




}

