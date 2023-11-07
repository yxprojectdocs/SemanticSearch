char* ptr = (char*)malloc (SIZE);
if (err) {
    abrt = 1;
    free(ptr);
}
...
if (abrt) {
    logError("operation aborted before commit", ptr);
}
// The following code illustrates a use after free error:
// When an error occurs, the pointer is immediately freed. However, this pointer is later incorrectly used in the logError function.