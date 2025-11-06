// function will get the length of file, number of elements, and return an unsigned short array
//
unsigned short* createBinaryList (long* fileSize, int* numberOfElements, FILE* vectorFile){
  
  
  fseek(vectorFile,  0, SEEK_END);
  
  *fileSize = ftell(vectorFile);
  *numberOfElements = *fileSize/sizeof(unsigned short);
  
  unsigned short* binaryList1 = new unsigned short[*numberOfElements];
  
  rewind(vectorFile);  
  
  for (int i = 0; i < *numberOfElements; i++) {
    fread(&binaryList1[i], sizeof(unsigned short), 1, vectorFile);
  }
  
  fclose(vectorFile);

  return binaryList1;
}
