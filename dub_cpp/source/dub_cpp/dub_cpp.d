import core.memory;

extern (C++) interface B {
public:
    extern (C++) int count();

private:
}

class D : B {
    extern (C++)int count() { return 11; }
};

extern (C++) B CreateB() {
    B inst = new D();
    core.memory.GC.addRoot(cast(void *)inst);
    return inst;
}
