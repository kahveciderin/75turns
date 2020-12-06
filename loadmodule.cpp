#include <zip.h>
#include <string>
#include <stdlib.h>
#include <cstring>
using namespace std;

int loadmodule(){


}

char* parsemanifest(char *manifest, char section[]){
    string man(manifest);
    int pos = man.find(section);
    int endpos = man.find("\n", pos);

    man = man.substr(pos + strlen(section), endpos - (pos + strlen(section)));
    
    char *ret = (char*)malloc(sizeof(char)*128);
    for(int i = 0; ret[i] = man.c_str()[i]; i++);


    return ret;



}
int loadpack(char *file) {

    int err = 0;
    zip *z = zip_open(file, 0, &err);

    const char *name = "manifest.mf"; //look for the manifest.mf in the zip file
    struct zip_stat st;
    zip_stat_init(&st);
    

    if(zip_stat(z, name, 0, &st) != 0){
        printf("ERROR: manifest.mf not found in pack '%s'!\n", file);
        return -1;
    }
    char *contents = new char[st.size]; //allocate memory for the contents of manifest

    //Read manifest
    zip_file *f = zip_fopen(z, name, 0);
    zip_fread(f, contents, st.size);
    zip_fclose(f);


    zip_close(z);

    
    printf("Pack %s v%s by %s\n",parsemanifest(contents, "NAME: "), parsemanifest(contents, "VERSION: "), parsemanifest(contents, "AUTHOR: "));

    //try not to cause a memory leak
    delete[] contents;
    return 0;
}
