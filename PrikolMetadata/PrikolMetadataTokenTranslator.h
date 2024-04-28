#pragma once

class PrikolMetadataTokenTranslator
	: public App::ITokenTranslator
{
private:
	static string16 _creationName;
public:
	bool TranslateToken(const char16_t* pToken, eastl::string16& dst) override;

	static void SetCreationName(string16 name) { _creationName = name; }
};

