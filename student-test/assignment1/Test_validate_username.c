#include "unity.h"
#include <stdbool.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "../../examples/autotest-validate/autotest-validate.h"
#include "../../assignment-autotest/test/assignment1/username-from-conf-file.h"

/**
* This function should:
*   1) Call the my_username() function in autotest-validate.c to get your hard coded username.
*   2) Obtain the value returned from function malloc_username_from_conf_file() in username-from-conf-file.h within
*       the assignment autotest submodule at assignment-autotest/test/assignment1/
*   3) Use unity assertion TEST_ASSERT_EQUAL_STRING_MESSAGE to verify the two strings are equal.  See
*       the [unity assertion reference](https://github.com/ThrowTheSwitch/Unity/blob/master/docs/UnityAssertionsReference.md)
*/
void test_validate_my_username()
{
    /**
     * TODO: Replace the line below with your code here as described above to verify your /conf/username.txt 
     * config file and my_username() functions are setup properly
     */
    const char *username = my_username();
    int fd = open("conf/username.txt",
	          O_RDONLY);
    if(fd == -1){
        perror("open");
	exit(EXIT_FAILURE);
    }
    else{
	int len = strlen(username);    
	char *buff = (char*)malloc(len + 1);
    	ssize_t bytes_read = read(fd, buff, len);
	if(bytes_read == -1){
	    perror("read");
	}
	else{
	    //printf("username: %s, config_name: %s\n", username, buff);		
	    assert(strcmp(username, buff) == 0);
	}
	close(fd);
    }
}
