int getValueFromArray(int *array, int len, int index) {

    int value;

    // check that the array index is less than the maximum

    // length of the array
    if (index < len) {

        // get the value at the specified index of the array
        value = array[index];
    }
    // if array index is invalid then outplut error message

    // and return value indicating error
    else {
        printf("Value is: %d\n", array[index]);
        value = -1;
    }

    return value;
}

// In the following code, the method retrieves a value from an array at a specific array index location that is given as an input parameter to the method
// However, this method only verifies that the given array index is less than the maximum length of the array but does not check for the minimum value (CWE-839). 
// This will allow a negative value to be accepted as the input array index, which will result in a out of bounds read (CWE-125) and may allow access to sensitive memory.
// The input array index should be checked to verify that is within the maximum and minimum range required for the array (CWE-129). 
// In this example the if statement should be modified to include a minimum range check, as shown below.