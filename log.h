static constexpr const char* StripPath(const char* pPath)
{
	const char* lastname = pPath;

	for (const char* p = pPath; *p != '\0'; p++)
	{
		if ((*p == '/' || *p == '\\') && (*(p + 1) != '\0'))
		{
			lastname = p + 1;
		}
	}

	return lastname;
}

static constexpr const char* FindEnd(const char* pPath)
{
	const char* lastpoint = pPath;

	while (*lastpoint != '\0')
	{
		lastpoint++;
		if (*lastpoint == '.')
		{
			break;
		}
	}

	return lastpoint;
}

struct fileNameStruct
{
	char name[1024];

	constexpr operator char* ()
	{
		return name;
	}
};

static constexpr fileNameStruct GetFileName(const char* pFilePath)
{
	fileNameStruct fileName = {};
	const char* strippedPath = StripPath(pFilePath);
	const char* pointPosition = FindEnd(strippedPath);

	for (unsigned int i = 0; i < pointPosition - strippedPath; i++)
	{
		*(fileName + i) = *(strippedPath + i);
	}

	fileName[pointPosition - strippedPath] = '\0';
	return fileName;
}
