#include "stdafx.h"
#include "PrikolMetadataTokenTranslator.h"

string16 PrikolMetadataTokenTranslator::_creationName;

bool PrikolMetadataTokenTranslator::TranslateToken(const char16_t* pToken, eastl::string16& dst)
{
	if (id(pToken) == id("prikol_metadata_creation_name")) {
		dst = _creationName;
		return true;
	}

	return false;
}