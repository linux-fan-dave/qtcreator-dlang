import core.memory;
import dub.project;
import std.string;

extern (C++, DubProject.Internal) {

    extern (C++) interface DProject {
    public:
        alias ErrorHandler=void function(bool succeeded, const char* error_description);
        extern (C++)void load(const char* path, ErrorHandler eh);
        extern (C++)void reload();

    private:
    }

    class DProjectImpl : DProject {
        extern (C++)void load(const char* path, ErrorHandler eh) { eh(true,  toStringz("hallo")); }
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
