module DProject;

import core.memory;
import dub.dub;
import std.string;
import std.conv;
import std.exception;
import dub.project;
import dub.package_;
import core.exception;
import dub.internal.vibecompat.inet.path;
import dub.generators.build;
import dub.generators.generator;
import dub.platform;
import dub.compilers.compiler;
//import dub.
import dub.project;
import std.stdio;
import core.runtime;


extern (C++, DubProject.Internal) {

    extern (C++) interface DProject {
    public:
        alias ErrorHandler=void function(bool succeeded, void* userData, const char* error_description);
        extern (C++)void load(const char* path, void* userData, ErrorHandler eh);
        extern (C++)void reload(void* userData, ErrorHandler eh);

    private:
    }

    class DProjectImpl : DProject {
        Package m_package;
        Dub m_dub;

        this() {
            std.stdio.writefln("DProjectImpl cstr");
        }

        ~this() {
            std.stdio.writefln("DProjectImpl dstr");
        }

        extern (C++)void load(const char* path, void* userData, ErrorHandler eh) {
            try {
                std.stdio.writefln("DProjectImpl load");
                // string strPath = to!string(path);
                // Dub dub  = new Dub(strPath);
                // dub.loadPackage();
                // eh(true, userData, toStringz("hallo 1 " ~ dub.project().name()));
                auto pth = to!string(path);
                NativePath root = NativePath(pth);
                NativePath file = NativePath(pth ~ "dub.json");
                std.stdio.writefln("DProjectImpl load 1");
                m_package = Package.load(root, file);
                std.stdio.writefln("DProjectImpl load 2");
                m_dub = new Dub();
                std.stdio.writefln("DProjectImpl load 3");

                m_dub.loadPackage(m_package);
                std.stdio.writefln("DProjectImpl load 4");

                BuildGenerator gen = new BuildGenerator(m_dub.project());

                // BuildPlatform platform;
                // auto config = dub.project.getDefaultConfiguration(platform);

                // GeneratorSettings settings;
                // settings.platform = platform;
                // settings.compiler = getCompiler("dmd");
                // settings.config = "library";
                // settings.buildType = "debug";
                // dub.generateProject("build", settings);
                //eh(true, userData, toStringz("hallo 1 " ~ pkg.name()));
            } catch(Exception e) {
                //eh(false, userData, toStringz(e.msg));
            }
        }
        extern (C++)void reload(void* userData, ErrorHandler eh) { }
    };

    extern (C++) DProject CreateDProject() {
        //Runtime.initialize();
        std.stdio.writefln("CreateDProject");
        DProject inst = new DProjectImpl();
        std.stdio.writefln("CreateDProject cstr should have run");
        GC.addRoot(cast(void *)inst);
        GC.setAttr(cast(void*)inst, GC.BlkAttr.NO_MOVE);
        std.stdio.writefln("CreateDProject finished");
        return inst;
    }

    extern (C++) void ReleaseDProject(DProject inst) {
        std.stdio.writefln("ReleaseDProject");
        core.memory.GC.removeRoot(cast(void *)inst);
    }
}

unittest
{
    import std.stdio;


    extern (C++) void callback(bool succeeded, void* userData, const char* error_description) {
        std.stdio.writefln("callback " ~ to!string(error_description));
    }
    int* i = new int(0);
    auto dp = CreateDProject();
    dp.load(toStringz("/home/david/DubProject/dub_cpp/"), i, &callback);
    ReleaseDProject(dp);

    dp = CreateDProject();
    dp.load(toStringz("/home/david/DubProject/dub_cppd/"), i, &callback);
    ReleaseDProject(dp);

    dp = CreateDProject();
    dp.load(toStringz("/home/david/DubProject/dub_cpp/dub.json"), i, &callback);
    ReleaseDProject(dp);
}
