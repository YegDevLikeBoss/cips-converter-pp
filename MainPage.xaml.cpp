//
// MainPage.xaml.cpp
// Implementation of the MainPage class.
//

#include "pch.h"
#include "MainPage.xaml.h"

using namespace uwpcpp;

using namespace Platform;
using namespace Windows::Foundation;
using namespace Windows::Foundation::Collections;
using namespace Windows::UI::Xaml;
using namespace Windows::UI::Xaml::Controls;
using namespace Windows::UI::Xaml::Controls::Primitives;
using namespace Windows::UI::Xaml::Data;
using namespace Windows::UI::Xaml::Input;
using namespace Windows::UI::Xaml::Media;
using namespace Windows::UI::Xaml::Navigation;
using namespace Windows::ApplicationModel::Core;
using namespace Windows::Storage; //AM for picking files
using namespace concurrency; //creating tasks


// The Blank Page item template is documented at https://go.microsoft.com/fwlink/?LinkId=402352&clcid=0x409

MainPage::MainPage()
{
	InitializeComponent();

	//auto coreTitleBar = CoreApplication::GetCurrentView();
	//coreTitleBar->TitleBar->ExtendViewIntoTitleBar = true;
	//ApplicationPageBackgroundThemeBrush
	//remove the solid-colored backgrounds behind the caption controls and system back button
	//ApplicationViewTitleBar titleBar = ApplicationView.GetForCurrentView().TitleBar;
	//titleBar.ButtonBackgroundColor = Colors.Transparent;
	//titleBar.ButtonInactiveBackgroundColor = Colors.Transparent;

	//MainPage::AppTitleBar->Height = coreTitleBar->TitleBar->Height;
	//Window::Current->SetTitleBar(AppTitleBar);
}


void uwpcpp::MainPage::Button_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	
}


void uwpcpp::MainPage::MenuImport_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	Pickers::FileOpenPicker^ fileOpenPicker = ref new Pickers::FileOpenPicker();
	fileOpenPicker->SuggestedStartLocation = Pickers::PickerLocationId::Desktop;
	fileOpenPicker->FileTypeFilter->Append(".jpg");
	fileOpenPicker->ViewMode = Pickers::PickerViewMode::Thumbnail;

	create_task(fileOpenPicker->PickSingleFileAsync()).then([this](Windows::Storage::StorageFile^ inputFile)
	{
		if (nullptr == inputFile)
			return;
	});
}
