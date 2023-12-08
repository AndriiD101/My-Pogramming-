void bytes_to_blocks(const int cols, const int offset, bool blocks[offset * 8][cols], const int rows, bool bytes[rows][8]) {
    for (int row = 0; row < offset; ++row) {
        for (int col = 0; col < cols; ++col) {
            for (int bit = 0; bit < 8; ++bit) {
                if (row * cols + col < rows) {
                    blocks[row*8+bit][col] = bytes[row * cols + col][bit];
                } else {
                    blocks[row*8+bit][col] = 0;
                }
            }
        }
    }
}

void bytes_to_blocks(const int cols, const int offset, bool blocks[offset*8][cols], const int rows, bool bytes[rows][8]) {
    size_t first=0;
    for (; first < offset; first++){
        size_t second=0;
        for (; second < cols; second++){
            size_t third=0;
            for (; third < 8; third++) {
                if(first*cols+second < rows) blocks[first*8+third][second] =  bytes[first*cols+second][third];
                else blocks[first*8+third][second] = 0;
            }
        }
    }
}