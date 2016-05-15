import core.memory;
import dub.project;
import std.string;

extern (C++, DubProject.Internal) {

    extern (C++) interface DProject {
    public:
        alias ErrorHandler=void function(bool succeeded, void* userData, const char* error_description);
        extern (C++)void load(const char* path, void* userData, ErrorHandler eh);
        extern (C++)void reload(void* userData, ErrorHandler eh);

    private:
    }

    class DProjectImpl : DProject {
        extern (C++)void load(const char* path, void* userData, ErrorHandler eh) {
            eh(true, userData, toStringz("hallo"));
        }
        extern (C++)void reload(void* userData, ErrorHandler eh) { }
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
