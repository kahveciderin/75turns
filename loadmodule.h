#ifndef LOADMODULE_H
#define LOADMODULE_H
extern void loadmodule(const char *filename);
extern char* parsemanifest(char *manifest, const char section[]);
extern int loadpack(const char file[]);
extern int index_handler;
extern void **handle;
#endif