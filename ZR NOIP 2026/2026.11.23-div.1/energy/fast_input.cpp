#define gc if(++ip==ie)fread(ip=buf,1,SZ,stdin)
const int SZ=1<<19;
char buf[SZ],*ie=buf+SZ,*ip=ie-1;
inline int read(){
    gc;while(*ip<'-')gc;
    bool f=*ip=='-';if(f)gc;
    int x=*ip&15;gc;
    while(*ip>'-'){x*=10;x+=*ip&15;gc;}
    return f?-x:x;
}
/*
	1. only useful when you use freopen
	2. please, don't use scanf and fast_input at the same time
*/
