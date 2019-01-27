#include "stdafx.h"
#include "xrManagedUILib.h"
#include "../xrUICore/UIHelper.h"

XRay::Test::Test()
{
	//CUILayoutInflater* layoutInflater = new CUILayoutInflater;
	//CUIViewGroup* view = (CUIViewGroup*) layoutInflater->Inflate("ui_mm_loading_screen.xml", nullptr);

	CUIXml xml;
	xml.Load(CONFIG_PATH, UI_PATH, "ui_mm_loading_screen.xml");

	XML_NODE* pNode = xml.GetRoot()->FirstChild();
	while (pNode)
	{
		XML_NODE* pElement = pNode->ToElement();
		if (pElement)
		{
			Log::Info(gcnew String(pElement->Value()));
			if (strstr(pElement->Value(), "ViewGroup"))
			{
				CUIViewGroup* view = new CUIViewGroup(xml, pElement);
				Log::Info("view group is created");
			}
			else if (strstr(pElement->Value(), "View"))
			{
				CUIView* view = new CUIView(xml, pElement);
				Log::Info("view is created");
			}
		}
		pNode = pNode->NextSibling();
	}
}

XRay::Test::~Test()
{

}

XRay::UIXML::UIXML() : NativeXML(new CUIXml)
{
	// ???
}

void XRay::UIXML::Load(::System::String^ XMLFileName)
{
	string128 XMLFileNameStr = { 0 };
	ConvertDotNetStringToAscii(XMLFileName, XMLFileNameStr);

	NativeXML->Load(CONFIG_PATH, UI_PATH, XMLFileNameStr);
}

// Да простят меня духи за этот маросс
#define TranslateCodeToNativeAndBack(Type, Delegate) \
	string128 XMLClassNameStr = { 0 }; \
	ConvertDotNetStringToAscii(XMLClassName, XMLClassNameStr); \
	CXml* refNativeXML = (CXml*)(pXML->EngineXMLClass().ToPointer()); \
	Type^ NetObject = gcnew Type((::System::IntPtr)UIHelper::Delegate(*refNativeXML, XMLClassNameStr, (CUIWindow*)pWND->EngineWNDClass().ToPointer())); \
	return NetObject

XRay::UIProgressBar^ XRay::UIHelperNET::CreateProgressBar(UIXML^ pXML, ::System::String^ XMLClassName, Window^ pWND)
{
	TranslateCodeToNativeAndBack(UIProgressBar, CreateProgressBar);
}

XRay::UIStatic^ XRay::UIHelperNET::CreateStatic(UIXML^ pXML, ::System::String^ XMLClassName, Window^ pWND)
{
	TranslateCodeToNativeAndBack(UIStatic, CreateStatic);
}