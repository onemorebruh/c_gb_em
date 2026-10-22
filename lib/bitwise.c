
int get_bit_via_mask(char byte, char mask){
    return (byte & mask) / mask;
}