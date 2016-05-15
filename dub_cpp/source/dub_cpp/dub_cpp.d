import core.memory;
import dub.project;

extern (C++, DubProject.Internal) {

    interface DProject {
public:
    extern (C++)void load();
    extern (C++)void reload();

private:
}

class DProjectImpl : DProject {
    extern (C++)void load () { }
    extern (C++)void reload() { }
};

extern (C++) DProject CreateDProject() {
    DProject inst = new DProjectImpl();
    core.memory.GC.addRoot(cast(void *)inst);
    return inst;
}

extern (C++) void ReleaseDProject(void* inst) {
    core.memory.GC.removeRoot(inst);
}
}
