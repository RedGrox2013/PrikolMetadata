#include "stdafx.h"
#include "EditMetadataCheat.h"
#include "PrikolMetadataTokenTranslator.h"

EditMetadataCheat::EditMetadataCheat()
	: _request(this)
{
}


EditMetadataCheat::~EditMetadataCheat()
{
}


void EditMetadataCheat::ParseLine(const ArgScript::Line& line)
{
	// This method is called when your cheat is invoked.
	// Put your cheat code here.

	_name = u"";

	bool hasArgs = false;
	auto nameArgs = line.GetOption("name", 1);
	if (nameArgs) {
		_name.assign_convert(nameArgs[0]);
		hasArgs = true;
	}

	if (!hasArgs) {
		App::ConsolePrintF("Error! No arguments. Enter help editMetadata to get more information.");
		return;
	}

	Sporepedia::ShopperRequest::Show(_request);
}

const char* EditMetadataCheat::GetDescription(ArgScript::DescriptionMode mode) const
{
	if (mode == ArgScript::DescriptionMode::Basic) {
		return "This cheat changes the metadata of the creation.";
	}
	else {
		return
			"This cheat changes the metadata of the creation.\n"
			"To change metadata, use the following options:\n"
			"-name \"<new name>\": to indicate the name of the creation (use quotes if there are spaces in the name)\n"
			"-author \"<new author>\": to indicate the author (use quotes if there are spaces in the title)\n"
			"-description <description>: for description (use quotes if description has spaces)";
	}
}

void EditMetadataCheat::OnShopperAccept(const ResourceKey& selection)
{
	cAssetMetadataPtr metadata;
	Pollinator::GetMetadata(selection.instanceID, selection.groupID, metadata);
	if (metadata->IsLocalized()) {
		HintManager.ShowHint(id("EditMetadataCheatFail"));
		return;
	}
	if (_name.compare(u"") != 0)
		metadata->mName = _name;

	ResourceManager.WriteResource(metadata.get());
	PrikolMetadataTokenTranslator::SetCreationName(metadata->mName);
	HintManager.ShowHint(id("EditMetadataCheatSuccessful"));
}