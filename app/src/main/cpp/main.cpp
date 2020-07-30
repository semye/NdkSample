#include <iostream>
#include <array>
#include <zconf.h>
#include <climits>
#include <cstring>

#include "Developer.h"

//全局变量
int height = 164;


using namespace std;


/**
 * 子线程中执行的方法
 * @return
 */
void *printhello(void *) {
    cout << "我在子线程中执行这段代码\n" << endl;
    return nullptr;
}


int main(int argc, char *argv[]) {
    const char *ye = "叶";
    const char *sheng = "盛";

    string a1111 = ye;
    string b1111 = sheng;

    string name111 = a1111 + b1111;

    cout << name111 << endl;


    cout << "================打印字符串==================" << endl;
    cout << "在C++中，用双引号括起来的一系列字符叫做字符串\n";

    //使用string类 声明两个string对象
    string name = "叶盛";
    string address = "杨浦区政府路18号波司登大厦";
    cout << name << endl;
    cout << address << endl;

    //获取当前程序的进程
    pid_t pid = getpid();
    cout << "当前程序的进程id: " << pid << endl;
    pid_t ppid = getppid();
    cout << "当前程序的父进程id: " << ppid << endl;
    uid_t uid = getuid();
    cout << "当前程序的uid: " << uid << endl;


    cout << &name << endl;


    int n_int = INT_MAX;
    short n_short = SHRT_MAX;
    long n_long = LONG_MAX;

    //声明方式
    int semye{1999};


    //cout 以10进制输出

    //打印数据类型长度
    cout << "short 的size: " << sizeof(short) << endl;
    cout << "int   的size: " << sizeof(int) << endl;
    cout << "long  的size: " << sizeof(long) << endl;


    cout << n_int << endl;
    cout << n_short << endl;
    cout << n_long << endl;


    int chest = 42;
    int waist = 0x42;
    int inseam = 042;

    cout << "===========================" << endl;
    cout << "chest:" << chest << endl;
    cout << "waist:" << waist << endl;
    cout << "inseam:" << inseam << endl;


    chest = 42;
    waist = 42;
    inseam = 42;

    cout << "===========================" << endl;
    cout << "chest:" << chest << endl;
    cout << hex;
    cout << "waist:" << waist << endl;
    cout << oct;
    cout << "inseam:" << inseam << endl;


    cout << "========>" << '\n';
    cout << "========>" << "\n";


    //常量的定义 被定义后无法修改
    const int Months = 12;

    //Months = 123; 编译错误

    //setf() 强迫使输出使用定点表示法
    cout.setf(ios_base::fixed, ios_base::floatfield);

    const float Million = 1.0e6;

    // float的有效位数为6位
    float tub = 10.0 / 3.0;
    cout << "float :" << tub * Million << endl;

    // double的有效位数为15位
    double mint = 10.0 / 3.0;
    cout << "double :" << mint * Million << endl;


    //浮点型精度
    float f1 = 2.34E+22f;
    float f2 = f1 + 1.0f;

    cout << "f1=" << f1 << endl;
    cout << "f2-f1=" << f2 - f1 << endl;


    string hello = "hello";

    string world = "world!";

    cout << hello + world << endl;


    char text[] = "d";

    cout << strlen(text) << endl;


    cout << sizeof(int) << endl;
    cout << sizeof(short) << endl;
    cout << sizeof(long) << endl;


    int update = 6;
    int *ppp;

    ppp = &update;

    cout << update << "==" << *ppp << endl;

    //使用new来声明 变量  存储在堆中 heap   使用delete来删除变量
    auto *zzz = new int;
    *zzz = 111;
    cout << dec;
    cout << "abc的值" << *zzz << endl;
    delete zzz;

    //模板类array 数组
    array<int, 5> ttt = {1, 2, 3, 4, 5};


    int zzzz[] = {1};

    cout << "数组长度" << sizeof zzzz << endl;


    //引用变量
    int see = 111;
    int &see1 = see;

    cout << see << endl;
    cout << see1 << endl;

//    list<string> *mylist = new list();


    Developer androidDeveloper;
    androidDeveloper.name = 18;

    androidDeveloper.writeCode();

    cout << androidDeveloper.hello() << endl;



    //获取当前的用户ID
    pid_t pgrp = getpgrp();
    printf("当前的用户pgrp为%d\n", pgrp);

    pthread_t pthread;
    int result = pthread_create(&pthread, nullptr, printhello, nullptr);
    if (result == 0) {
        printf("启动线程=======\n");
    }




//    getchar();


    printf("%d\n", argc);
    for (int i = 0; i < argc; ++i) {
        printf("%s\n", argv[i]);
    }

    string c = "hello world";


    cout << c;

    time_t timer = time(NULL);
    printf("ctime is %s\n", ctime(&timer));//得到日历时间


    char tex[100] = "hello";
    const char *text1 = "semyedasfsghjg1";
    //拼接字符串
    strcat(tex, text1);
    printf("====>%s\n", tex);

    char a = 'a';

//    char *result = strchr(tex, a);

//    printf("%c\n", (unsigned char) &result);

//    p = memchr(text, 'o', strlen(text));
//
//    if (p) {
//        printf("%s\n", p);
//    }


    struct tm *tblock;
    timer = time(NULL);
    tblock = localtime(&timer);
    printf("Local time is: %s", asctime(tblock));

    //stdio.h
    FILE *ma = fopen("main.c", "ab+");
    printf("%p", &ma);
    fclose(ma);
    return 0;
}







//
//void copyFile() {
//
//}
//
//void getPidByName(pid_t *pid, char *task_name) {
//    DIR *dir;
//    struct dirent *ptr;
//    FILE *fp;
//    char filepath[50];
//    char cur_task_name[50];
//    char buf[BUF_SIZE];
//
//    dir = opendir("/proc");
//    if (NULL != dir) {
//        while ((ptr = readdir(dir)) != NULL) //循环读取/proc下的每一个文件/文件夹
//        {
//            //如果读取到的是"."或者".."则跳过，读取到的不是文件夹名字也跳过
//            if ((strcmp(ptr->d_name, ".") == 0) || (strcmp(ptr->d_name, "..") == 0))
//                continue;
//            if (DT_DIR != ptr->d_type)
//                continue;
//
//            sprintf(filepath, "/proc/%s/status", ptr->d_name);//生成要读取的文件的路径
//            fp = fopen(filepath, "r");
//            if (NULL != fp) {
//                if (fgets(buf, BUF_SIZE - 1, fp) == NULL) {
//                    fclose(fp);
//                    continue;
//                }
//                sscanf(buf, "%*s %s", cur_task_name);
//
//                //如果文件内容满足要求则打印路径的名字（即进程的PID）
//                if (!strcmp(task_name, cur_task_name)) {
//                    sscanf(ptr->d_name, "%d", pid);
//                }
//                fclose(fp);
//            }
//        }
//        closedir(dir);
//    }
//}

//void getNameByPid(pid_t pid, char *task_name) {
//    char proc_pid_path[BUF_SIZE];
//    char buf[BUF_SIZE];
//
//    sprintf(proc_pid_path, "/proc/%d/status", pid);
//    FILE *fp = fopen(proc_pid_path, "r");
//    if (NULL != fp) {
//        if (fgets(buf, BUF_SIZE - 1, fp) == NULL) {
//            fclose(fp);
//        }
//        fclose(fp);
//        sscanf(buf, "%*s %s", task_name);
//    }
//}

//
//void getSeconds(unsigned long *par);
//
//
//void getSeconds(unsigned long *par) {
//    /* 获取当前的秒数 */
//    *par = time(NULL);
//    return;
//}


///*copyfile,ifway==1,useread/write,elseusefread/fwrite,atthesametime,itcountstimeconsumed*/
//int mycopy(int way, int step) {
//    time_t start_tm, stop_tm;
//    FILE *srcf, *destf;
//    char buff[1024];
//    int i, sfd, dfd;
//    //getstarttime
//    time(&start_tm);
//    for (i = 0; i < 1024; i = i + step) {
//        if (way == 1) {
//            sfd = open("in.txt", O_RDONLY, 0644);
//            dfd = open("out.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
//            read(sfd, buff, step);
//            write(dfd, buff, step);
//            close(sfd);
//            close(dfd);
//        } else {
//            srcf = fopen("in.txt", "r");
//            destf = fopen("out.txt", "w");
//            fread(buff, step * sizeof(char), 1, srcf);
//            fwrite(buff, step * sizeof(char), 1, destf);
//            close(srcf);
//            close(destf);
//        }
//    }
//    //getstoptime
//    time(&stop_tm);
//    //printinformationfortesting
//    printf("\ntimeusedforcopyfilebymeansof%s,%dbytepertime:%ds", way ? "read,write" : "fread,fwrite", step,
//           (int) (stop_tm - start_tm));
//    return 0;
//}
//
//int main(int argc, char **argv) {
//
//    /*当上述函数中nbytes,size和nitems都取值为1时（即一次读写一个字节），比较这两种程序的执行效率。*/
//    if (mycopy(1, 1))
//        return 1;
//    if (mycopy(0, 1))
//        return 1;
//    /*当nbytes取1024字节，size取1024字节，且nitems取1时（即一次读写1024字节），再次比较这两种程序的执行效率。*/
//    if (mycopy(1, 1024))
//        return 1;
//    if (mycopy(0, 1024))
//        return 1;
//    return 0;
//}


//void change(void *m) {
//    printf("我是线程哈哈哈哈哈哈哈");
//}





#define MYPORT 10179
//listening port
#define BACKLOG 10 //max connect requests
#define MAXDATASIZE 1024 //max data buff
//
//void startService() {
//    int sock_fd, new_fd, fd, numbytes;
//    struct sockaddr_in my_addr;
//    struct sockaddr_in their_addr;
//    int sin_size;
//    char buf[MAXDATASIZE];
//    /*socket()*/
//    if ((sock_fd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
//        perror("socket create error");
//        exit(1);
//    }
//    my_addr.sin_family = AF_INET;
//    my_addr.sin_port = htons(MYPORT);
//    my_addr.sin_addr.s_addr = INADDR_ANY;
//    bzero(&(my_addr.sin_zero), 8);
//    /*bind()*/
////    if (bind(sock_fd, (struct sockaddr *) &my_addr, sizeof(struct sockaddr))) {
////        perror("bind error");
////        exit(1);
////    }
//    /*listen()*/
//    if (listen(sock_fd, BACKLOG) == -1) {
//        perror("listen error");
//        exit(1);
//    }
//    /*accept()*/
//    while (1) {
//        sin_size = sizeof(struct sockaddr_in);
////        if ((new_fd = accept(sock_fd, (struct sockaddr *) &their_addr, reinterpret_cast<socklen_t *>(&sin_size))) ==
////            -1) {
////            perror("accept error");
////            continue;
////        }
//        printf("received a connect from:%s\n", inet_ntoa(their_addr.sin_addr));
//        /*recv()*/
//        fd = open("target.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
//        while ((numbytes = recv(new_fd, buf, MAXDATASIZE, 0)) > 0) {
//            write(fd, buf, numbytes
//            );
//        }
//        close(new_fd);
//        close(fd);
//        printf("File successfully received.\n");
//        /* clean up child processes */
//        while (waitpid(-1, NULL, WNOHANG) > 0);
//    }
//}

//
//void gd() {
//    int fd, n;
//    char buf[256];
//    fd = open("fifo", O_RDONLY);
//    while ((n = read(fd, buf, sizeof(buf)) != -1)) {
//        puts(buf);
//    }
//    close(fd);
//}

int maitt() {
    clock_t start_t, end_t;
    double total_t;
    start_t = clock();
    printf("Welcome To SemyeClient!\n");


    pid_t pid = getpid();
    printf("pid of this process:%d\n", pid);
    uid_t uid = getuid();
    printf("uid of this process:%d\n", uid);

    pid_t pid1 = fork();
    printf("pid1 of this process:%d\n", pid1);


    if (pid1 == 0) {


        printf("子程序运行中。。。。。。\n");

    } else {

        int i;
        int a = 100;
        int *p = &a;
        printf("%p\n", p);


        printf("%lu\n", sizeof(float));

        float ddd = (float) (20000.0 / 3.0);
        printf("=====>%f\n", ddd);

        double ddd2 = 20000.0 / 3.0;
        printf("=====>%f\n", ddd2);


        char *aaa = static_cast<char *>(calloc(100, 10));

        printf("%s int 存储大小 : %lu \n", SEMYE, sizeof(int));
        printf("开始一个大循环，start_t = %ld\n", start_t);
        for (i = 0; i < 10000000; i++) {

        }

        char tex1[100] = "hello world";
        char tex2[100] = "semye";
        strcat(tex1, tex2);

        printf("=======>%s\n", tex1);


        FILE *file = fopen("b.txt", "a");
        if (!file) {
            perror((const char *) file);
        }

        fputs("hello world!!", file);
        fputs("hello world!", file);
        fputs("hello world!", file);
        fclose(file);


        FILE *file1 = fopen("b.txt", "r");
        char buff[1024];
        fgets(buff, 1024, file1);
        printf("====>%s\n", buff);
        fclose(file1);


        end_t = clock();
        printf("大循环结束，end_t = %ld\n", end_t);


        total_t = (double) (end_t - start_t) / CLOCKS_PER_SEC;
        printf("CPU 占用的总时间：%f\n", total_t);
        printf("程序退出...\n");
    }


    return 0;
}


//
//int testpipe() {
//    int sfd, dfd, n, chan[2];
//    char buff[1024];
//    sfd = open("in.txt", O_RDONLY, 0644);
//    dfd = open("111.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
//    pipe(chan);
//
//    if (fork()) {
//        while ((n = read(sfd, buff, 1024)) > 0) {
//            close(chan[0]);
//            write(chan[1], buff, n);
//            close(chan[1]);
//        }
//    } else {
//        close(chan[1]);
//        read(chan[0], buff, 1024);
//        write(dfd, buff, strlen(buff));
//        close(chan[0]);
//    }
//
//    close(sfd);
//    close(dfd);
//    return 0;
//}
//
//
//ymgd() {
//    int fd;
//    char buf[256];
//    mknod("fifo", S_IFIFO | 0666, 0);
//    fd = open("fifo", O_WRONLY);
//    while (gets(buf) != NULL) {
//        write(fd, buf, strlen(buf) + 1);
//    }
//    close(fd);
//}
//
//
//gd() {
//    int fd, n;
//    char buf[256];
//    fd = open("fifo", O_RDONLY);
//    while ((n = read(fd, buf, sizeof(buf)) != -1)) {
//        puts(buf);
//    }
//    close(fd);
//}
//
//
//#define maxsize 1000
////定义原始分配区的大小。
//struct map {
//    unsigned m_size;  //本表项所指空闲区的大小。
//    char *m_addr;    //本表项所指空闲区的首地址。
//    struct map *next, *prior;  //本表项的前后表项。
//};
//
//struct map *coremap, *start;  //coremap指向首表项，start指向当前的查找首表项。
//
//char *mmalloc(unsigned size) {  //分配空闲区的函数。
//    struct map *current = start; //记录查找的起点。
//    char *c;
//    do {
//        if (start->m_size > size) { //有足够大的空闲区，有余。
//            start->m_size = start->m_size - size; //减小分配过的表项空间。
//            c = start->m_addr;
//            start->m_addr += size; //修改表项的首地址。
//            return c;
//        } else if (start->m_size == size) { //有正好大小的空闲区。
//            start->next->prior = start->prior; // 从链表中删除该表项。
//            start->prior->next = start->next; // 从链表中删除该表项。
//            start->m_size = 0;
//            return start->m_addr;
//        } else
//            start = start->next; //当前表项所指的空闲区不够，start指向下一个表项。
//    } while (start != current); // 一直循环查找表项，直到回到起点。
//    return NULL;     //没有找到合适大小的分配区，分配失败。
//}
//
//int mfree(unsigned size, char *addr) { //释放的函数。
//    struct map *current = coremap; //
//    struct map *temp;
//    //若释放的空间在循环链表的首表项的前头，则要插入首表项。
//    if (coremap->m_addr > addr && ((coremap->m_addr - addr) > (signed) size)) {
//        temp = (struct map *) malloc(sizeof(struct map)); //新建首表项。
//        temp->m_addr = addr;
//        temp->m_size = size;
//        temp->next = coremap;
//        temp->prior = coremap->prior;
//        coremap->prior->next = temp;//插入循环链表
//        coremap->prior = temp;
//        coremap = coremap->prior;
//        return 1;//释放成功。
//    }
//        // 若释放的空间紧挨着循环链表的首表项的前头，则要修改首表项。
//    else if (coremap->m_addr > addr && (coremap->m_addr - addr == size)) {
//        coremap->m_addr = addr;//修改首表项的首地址。
//        coremap->m_size += size;
//        return 1;//释放成功。
//    }
//    // 若释放的空间在循环链表的首表项的后头，则有四种情况：
//    do {          //若释放的空间不紧挨着别的空闲区的边界。
//        if ((current->m_addr + current->m_size < addr) && (current->next->m_addr > addr + size)) {
//            temp = current->next;
//            current->next = (struct map *) malloc(sizeof(struct map));
//            current->next->prior = current;
//            current->next->next = temp;
//            current->next->m_size = size;
//            current->next->m_addr = addr;
//            temp->prior = current->next;
//            return 1; //释放成功。
//        }
//            //若释放的空间紧挨着上边空闲区的边界，不紧挨着下边空闲区的边界。
//        else if ((current->m_addr + current->m_size == addr) && (current->next->m_addr > addr + size)) {
//            current->m_size += size;
//            return 1; //释放成功。
//        }
//            // 若释放的空间不紧挨着上边空闲区的边界，紧挨着下边空闲区的边界。
//        else if ((current->m_addr + current->m_size < addr) && (current->next->m_addr == addr + size)) {
//            current->next->m_addr = addr;
//            current->next->m_size += size;
//            return 1; //释放成功。
//        }
//            // 若释放的空间紧挨着上边空闲区的边界，紧挨着下边空闲区的边界。
//        else if ((current->m_addr + current->m_size == addr) && (current->next->m_addr == addr + size)) {
//            current->m_size += (size + current->next->m_size);
//            current->next->next->prior = current;
//            current->next = current->next->next;
//            return 1; //释放成功。
//        } else current = current->next; //释放的空间不在当前表项和下一表项间。
//    } while (current != coremap);//一直寻找，直到回到起点。
//    return 0; //没有匹配的空间可以释放，释放失败。
//}
//
//void printall() {
//    struct map *temp = coremap;
//    printf("\n");
//    do {
//        printf("%u,%u;", temp->m_addr, temp->m_size);
//        temp = temp->next;
//    } while (temp != coremap);
//}
//
//
//excute() {
//    char c;
//    char *addr;
//    unsigned size;
//    printf("Welcome to use my operation system!");
//    coremap = (struct map *) malloc(sizeof(struct map));//创建循环链表的首表项。
//    coremap->m_addr = (char *) malloc(maxsize);// 分配给首表项原始的一片空间。
//    coremap->m_size = maxsize;
//    coremap->prior = coremap->next = coremap;//循环关系。
//    start = coremap;//设置当前指针。
//    do {
//        printall();
//        printf("\nWhat area do you want to malloc or free? m or f\n");
//        scanf("%s", &c);
//        if (c == 'm') {//分配空间。
//            scanf("%u", &size);
//            if (!mmalloc(size))
//                printf("Sorry!There's no area for this size what can be malloced.");
//        } else if (c == 'f') {//释放空间。
//            scanf("%u,%u", &size, &addr);
//            if (mfree(size, addr) != 1)
//                printf("Sorry!There's no area which you can free.");
//        } else break;//其他字母推出。
//    } while (c == 'm' || c == 'f');
//}

//int copyfile(int argc, char *argv[]) {
//    int fd1 = open(argv[1], O_RDONLY);//只读
//    creat(argv[2], 0660);
//    int fd2 = open(argv[2], O_WRONLY);//只写
//
//    char ch;
//    while (true) {
//        int rdRes = read(fd1, &ch, 1);
//        if (rdRes == -1) {
//            printf("read %s error\n", argv[1]);
//            return -1;
//        } else if (rdRes == 0) {
//            printf("copy %s success\n", argv[1]);
//            break;
//        } else if (rdRes == 1) {
//            int wrRes = write(fd2, &ch, 1);
//            if (wrRes != 1) {
//                printf("write %s error\n", argv[2]);
//                return -1;
//            }
//        } else {
//            printf("unknow error\n");
//            return -1;
//        }
//    }
//    close(fd1);
//    close(fd2);
//}


#define READ_BUFF 100

//int copy3(int argc, char *argv[]) {
//    printf("%s\n", argv[1]);
//    printf("%s\n", argv[2]);
//    FILE *fp1, *fp2 = NULL;
//    int c = 0;
//    char buf[READ_BUFF];
//    fp1 = fopen(argv[1], "rb");
//    fp2 = fopen(argv[2], "wb");
//
//    if (fp1 == NULL || fp2 == NULL) {
//        printf("open %s or %s failed:%s\n", argv[1], argv[2], strerror(errno));
//        return -2;
//    }
//    while ((c = fread(buf, sizeof(char), READ_BUFF, fp1)) > 0) {
//        fwrite(buf, sizeof(char), c, fp2);
//    }
//    fclose(fp1);
//    fclose(fp2);
//    return 0;
//}

//int pip2e2() {
//    int sfd, dfd, n, chan[2];
//    char buff[1024];
//    sfd = open("in.txt", O_RDONLY, 0644);
//    dfd = open("111.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
//    pipe(chan);
//
//    if (fork()) {
//        while ((n = read(sfd, buff, 1024)) > 0) {
//            close(chan[0]);
//            write(chan[1], buff, n);
//            close(chan[1]);
//        }
//    } else {
//        close(chan[1]);
//        read(chan[0], buff, 1024);
//        write(dfd, buff, strlen(buff));
//        close(chan[0]);
//    }
//
//    close(sfd);
//    close(dfd);
//    return 0;
//}


//int hah(int argc, char **argv) {
//    int sockfd, numbytes, fd, n;
//    struct hostent *he;
//    struct sockaddr_in their_addr;
//    char buf[1024];
//    he = gethostbyname(argv[1]);    /*socket()*/  sockfd = socket(AF_INET, SOCK_STREAM, 0);
//    their_addr.sin_family = AF_INET;
//    their_addr.sin_port = htons(atoi(argv[2]));
//    their_addr.sin_addr = *((struct in_addr *) he->h_addr);
//    bzero(&(their_addr.sin_zero), 8);    /*connect()*/  connect(sockfd, (struct sockaddr *) &their_addr,
//                                                                sizeof(struct sockaddr));
//    fd = open("in.txt", O_RDONLY, 0644);  /*send()*/  while ((n = read(fd, buf, 1024)) > 0) {
//        printf("%d\n", n);
//        if (n < 1024) buf[n] = '\0';
//        send(sockfd, buf, n, 0);
//    }
//    close(fd);
//    close(sockfd);
//    return 0;
//}

//    char aaa[100];
//    gets(aaa);
//    puts(aaa);


//    static int array[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
//
//
//    for (int i = 0; i < 10; i++) {
//        printf("%d ", array[i]);
//    }
//    printf("==========\n");
//    static int array2[10] = {0, 1, 2, 3, 4};
//
//    for (int i = 0; i < array2; i++) {
//        printf("%d ", array2[i]);
//    }




//    static int array3[10][10][10][10][10][10] = {};
//    for (int j = 0; j < sizeof(array3); ++j) {
//
//    }
//    int n;
//    char buf[1024];
//    int fd1 = open(argv[0], O_RDONLY);//只读
//    creat(argv[2], 0660);
//    int fd2 = open(argv[2], O_WRONLY);//只写
//    while ((n = (int) read(fd1, buf, BUF_SIZE)) > 0) {
//        write(fd2, buf, n);
//    }




//    char task_name[50];

//
//    getNameByPid(pid, task_name);
//
//    /*
//    strcpy(task_name, argv[0]+2);
//    printf("task name is %s\n", task_name);
//    getPidByName(task_name);
//    */
//    printf("getNameByPid:%s\n", task_name);
//    getPidByName(&pid, task_name);
//    printf("getPidByName:%d\n", pid);
//    sleep(1000);




//    char hello[] = "helloworld!";
//
//    printf("Greeting message: %s\n", hello);






//    printf("Hello, World!\n");
//    bubbleSort();
//
//    //指针的定义
//
//
//    int a = 1;
//    float b = 2.3;
//    char c = 'c';
//
//    int *pa = &a;
//    float *pb = &b;
//    char *pc = &c;
//
//    printf("%p\n", pa);
//    printf("%p\n", pb);
//    printf("%p\n", pc);
//
//
//    struct Books Book1;        /* 声明 Book1，类型为 Books */
//    struct Books Book2;        /* 声明 Book2，类型为 Books */
//
//    /* Book1 详述 */
//    strcpy(Book1.title, "C Programming");
//    strcpy(Book1.author, "Nuha Ali");
//    strcpy(Book1.subject, "C Programming Tutorial");
//    Book1.name = "HELLO";
//    Book1.book_id = 6495407;
//
//    /* Book2 详述 */
//    strcpy(Book2.title, "Telecom Billing");
//    strcpy(Book2.author, "Zara Ali");
//    strcpy(Book2.subject, "Telecom Billing Tutorial");
//    Book2.book_id = 6495700;
//
//    /* 输出 Book1 信息 */
//    printf("Book 1 title : %s\n", Book1.title);
//    printf("Book 1 author : %s\n", Book1.author);
//    printf("Book 1 subject : %s\n", Book1.subject);
//    printf("Book 1 book_id : %d\n", Book1.book_id);
//
//    /* 输出 Book2 信息 */
//    printf("Book 2 title : %s\n", Book2.title);
//    printf("Book 2 author : %s\n", Book2.author);
//    printf("Book 2 subject : %s\n", Book2.subject);
//    printf("Book 2 book_id : %d\n", Book2.book_id);
//
//
//    FILE *fp;
//
//    //打开文件,文件不存在就创建文件
//    fp = fopen("/Users/yesheng/Documents/test.txt", "a+");
//    //写入数据方式1
//    fprintf(fp, "This is testing for fprintf...\n");
//    //写入数据方式2
//    fputs("This is testing for fputs...\n", fp);
//
////    fread( fp);
//
//    //关闭文件
//    fclose(fp);


//    int a = 2147483647;//2的31次方 -2147483648~2147483647
//    short int j = 32767;//-32768~32767
//    double b = 1.0;
//
//    float c = 0.88;
//
//
//    printf("%d\n", a);
//    size_t size = sizeof(a);
//    printf("%zu个字节\n", size);
//    printf("%d\n", j);
//    printf("%zu个字节\n", sizeof(j));
//    printf("%.f\n", b);
//    printf("%f\n", c);



//    //++i与i++的区别
//
//    int i,j;
//    i=j=1;
//    int m,n;
//    n=i++;
//    m=++j;
//    printf("i++是先赋值再运算==>%d===%d\n",n,i);
//    printf("++i是先运算再赋值==>%d===%d\n",m,j);
//
//

//
//
//
//
//
//
//
//    printf("%s\n","hello world");
//
//    Books name;
//    strcpy( name.title, "hello");
//    strcpy( name.author, "Nuha Ali");
//    strcpy( name.subject, "C Programming Tutorial");
//    name.book_id = 6495407;

//    exercises2_6();




//    int c;
//
//    printf( "Enter a value :");
//    c = getchar( );
//
//    printf( "\nYou entered: ");
//    putchar( c );

//    char str[100];
//
//    printf( "Enter a value :");
//    gets( str );
//
//    printf( "\nYou entered: ");
//    puts( str );



//    FILE *fp;
//      fp= fopen("/Users/yesheng/Documents/test.txt", "r");
//    //读取数据
//    char buff[255];
//    //读取数据方式1
//    fscanf(fp, "%s", buff);
//    printf("1 : %s\n", buff );
//    //读取数据方式2
//    fgets(buff, 255, (FILE*)fp);
//    printf("2: %s\n", buff );
//    //读取数据方式3
//    fgets(buff, 255, (FILE*)fp);
//    printf("3: %s\n", buff );
//
//
//
//    //关闭文件
//    fclose(fp);
//
//

//
//
//    //常量
//    const int age=25;
//
//    int _=1;
//
//    int ma=max(3,5);
//
//    int study(int);
//
//    //数组
//    int array[10];
//    for (int i=0; i<10; i++) {
//        array[i]=i;
//    }
//
//    //字符串
//    char helloworld[]="hello world";
//
//    char semye[]=" semye";
//
//
//    strcat(helloworld,semye);
//
//    printf("%s\n", helloworld);
//
//    int var1=123;
//    //指针
//    int *p=&var1;
//
//    //空指针
//    int  *ptr = NULL;
//
//    printf("var1 变量的地址： %x\n", p);
//    printf("var1 变量的地址： %d\n", *p  );
//
//
//
//    study(99);
//
//    printf("比较大的数是%d\n",ma);
//
//    printf("我的身高是%d厘米\n",height);
//
//    printf("我的年龄是%d岁\n",age);
//
//    printf("%s\n %d\n","hello world!",_);
//


















