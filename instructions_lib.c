//do nothing
void NOP(){
    return;
}

//LOAD right into left
void LD(char* left_ptr, char* right_ptr){
    *left_ptr = *right_ptr;
    return;
}