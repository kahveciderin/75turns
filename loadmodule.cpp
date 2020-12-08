#include <zip.h>
#include <string>
#include <stdlib.h>
#include <cstring>
#include <filesystem>
#include <iostream>
#include <fstream>

#include <dlfcn.h>

#define MAX_MODS 64
using namespace std;
int index_handler = 0;
void *handle[MAX_MODS];

int loadmodule(char *filename){
    void (*init)();
    handle[index_handler] = dlopen (filename, RTLD_LAZY);

    //printf("%s %s %x\n", filename, dlerror(), handle[index_handler]);
    init = (void (*)())dlsym(handle[index_handler], "init");
    //printf("%s\n", dlerror());
    (init)();
    index_handler++;
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
    printf("Pack %s v%s by %s\n",parsemanifest(contents, "NAME: "), parsemanifest(contents, "VERSION: "), parsemanifest(contents, "AUTHOR: "));
    
    char *load = parsemanifest(contents, "LOAD:");
    free(contents);

    
    // Returns first token 
    char *token = strtok(load, " ");
  
    char *tmpname = (char*)malloc(sizeof(char)*256);
    while (token != NULL)
    {
        printf("\n\nEnabling %s...\n", token);
        if(zip_stat(z, token, 0, &st) != 0){
        printf("ERROR: %s not found in pack '%s', skipping!\n", token, file);
        break;
        }


        char *contents = new char[st.size]; //allocate memory for the contents of the shared library

        //Read so file
        zip_file *f = zip_fopen(z, token, 0);
        zip_fread(f, contents, st.size);
        
        tmpnam(tmpname);
        
        
        FILE * pFile;
        pFile = fopen (tmpname, "wb");
        fwrite (contents, sizeof(char), st.size, pFile);
        fclose (pFile);

        loadmodule(tmpname);
        
        zip_fclose(f);
        //remove(tmpname);
        free(contents);

        printf("\n\nEnabled %s...\n", token);
        token = strtok(NULL, " ");
        
    }
    



    zip_close(z);

    return 0;
}

int main(){//remove
    loadpack("vanilla.zip");
}
