#pragma once

#include <Spore\BasicIncludes.h>

class EditMetadataCheat 
	: public ArgScript::ICommand
	, public Sporepedia::IMultiShopperListener
{
private:
	Sporepedia::ShopperRequest _request;

	string16 _name, _author, _description;
public:
	EditMetadataCheat();
	~EditMetadataCheat();

	// Called when the cheat is invoked
	void ParseLine(const ArgScript::Line& line) override;
	
	// Returns a string containing the description. If mode != DescriptionMode::Basic, return a more elaborated description
	const char* GetDescription(ArgScript::DescriptionMode mode) const override;

	void OnShopperAccept(const eastl::vector<ResourceKey>& selection) override;
};

