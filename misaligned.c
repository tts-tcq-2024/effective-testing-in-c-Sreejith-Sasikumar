#include <stdio.h>
#include <assert.h>
#include <string.h>

int printColorMap() {
    const char* majorColor[] = {"White", "Red", "Black", "Yellow", "Violet"};
    const char* minorColor[] = {"Blue", "Orange", "Green", "Brown", "Slate"};
    int i = 0, j = 0;
    for(i = 0; i < 5; i++) {
        for(j = 0; j < 5; j++) {
            printf("%d | %s | %s\n", i * 5 + j, majorColor[i], minorColor[i]);
        }
    }
    return i * j;
}

int main() {
    char bufferForPrintedColorMap[500]={0};
    const char* expectedFirstRowinMap = "0 | White | Blue\n";
    const char* expectedSecondRowinMap = "1 | White | Orange\n";
    
    setvbuf(stdout, bufferForPrintedColorMap, _IOFBF, 500);
    
    int result = printColorMap();

    char *firstLine_found = strstr(bufferForPrintedColorMap,expectedFirstRowinMap);
    char *secondLine_found = strstr(bufferForPrintedColorMap,expectedSecondRowinMap);

    assert(firstLine_found != NULL);
    assert(secondLine_found != NULL);
    assert(result == 25);
    printf("All is well (maybe!)\n");
    return 0;
}
