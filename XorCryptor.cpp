#include <fstream>
#include <cstring>
bool cryptor(const char *srcName,const char*destName,const char*key)
{
	std::ifstream fsrc(srcName,std::ios::binary);
	std::ofstream fdest(destName,std::ios::binary);
	if(!fsrc.is_open() || fdest.is_open())
		return false;
	size_t keyLen = strlen(key),index = 0;
	char fBuffer[1];
	while(fsrc)
	{
		fsrc.read(fBuffer,1);
		fBuffer[0] ^= key[index++ % keyLen];
			fdest.write(fBuffer,1);
	}
	fsrc.close();
	fdest.close();
	return true;
}