#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <linux/limits.h>
#include <string.h>
#include <sys/stat.h>

char buf[PATH_MAX];

int walk(const char *dirname, int do_dirs, const char *searchf)
{
    DIR *dp;
    struct stat st;
    struct dirent *dirp;
    int retval = 0;

    size_t len = strlen(dirname);

    if ((dp = opendir(dirname)) == NULL)
    {
        // perror(dirname);
        return 1;
    }

    strncpy(buf, dirname, len);

    while ((dirp = readdir(dp)) != NULL)
    {
        if (strcmp(dirp->d_name, ".") == 0 ||
            strcmp(dirp->d_name, "..") == 0)
            continue;

        buf[len] = '/';
        buf[len + 1] = '\0';

        strcat(buf, dirp->d_name);

        if(strcmp(searchf, dirp->d_name) == 0) 
        {
            printf("\npath: %s", buf);
        }

        if (lstat(buf, &st) == -1)
        {
            retval = 1;
            continue; /////
        }

        if (S_ISDIR(st.st_mode))
        {
            if (walk(buf, do_dirs, searchf) == 1)
            {
                retval = 1;
                continue;    ////
            }
        }

        buf[len] = '\0';
    }

    closedir(dp);
    return retval;
}

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        fprintf(stderr, "Usage: %s DIR\n", argv[0]);
        exit(1);
    }

    char *searchf = "find_me";
    exit(walk(argv[1],  1, searchf));
}