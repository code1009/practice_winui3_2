#include "pch.h"
#include "MainWindow.xaml.h"
#if __has_include("MainWindow.g.cpp")
#include "MainWindow.g.cpp"
#endif

#include "MainPage.xaml.h"
#include "MyPage.xaml.h"



/////////////////////////////////////////////////////////////////////////////
//===========================================================================
namespace winrt
{

using namespace WinUI3App;

/*
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
*/

}



/////////////////////////////////////////////////////////////////////////////
//===========================================================================
namespace winrt
{
using namespace Microsoft::UI::Xaml;
using namespace Microsoft::UI::Xaml::Controls;
using namespace Microsoft::UI::Xaml::Media;
using namespace Microsoft::UI::Xaml::Media::Animation;
using namespace Microsoft::UI::Xaml::Navigation;
//using namespace Microsoft::UI::Xaml::Interop; // 추가된 네임스페이스
using namespace Windows::UI::Xaml::Interop;
}



/////////////////////////////////////////////////////////////////////////////
//===========================================================================
// To learn more about WinUI, the WinUI project structure,
// and more about our project templates, see: http://aka.ms/winui-project-info.
namespace winrt::WinUI3App::implementation
{
	MainWindow::MainWindow()
	{
		InitializeComponent();

		// Xaml objects should not call InitializeComponent during construction.
		// See https://github.com/microsoft/cppwinrt/tree/master/nuget#initializecomponent

		/*
		winrt::Windows::Foundation::IInspectable item;
		if (ContentFrame().Content() == nullptr)
		{
			item = NavigationView().MenuItems().GetAt(0);
		}
		else
		{
			item = NavigationView().SelectedItem();
		}
		*/

		ContentFrame().Navigate(xaml_typename<WinUI3App::MainPage>());

		//NavigationView().SelectionChanged({ this, &MainWindow::OnSelectionChanged });
	}

	void MainWindow::OnSelectionChanged(NavigationView const& sender, NavigationViewSelectionChangedEventArgs const& args)
	{
		auto selectedItem = args.SelectedItem().as<NavigationViewItem>();
		hstring selectedTag = unbox_value<hstring>(selectedItem.Tag());

		if (selectedTag == L"MyPage")
		{
			ContentFrame().Navigate(xaml_typename<WinUI3App::MyPage>());
		}
		if (selectedTag == L"MainPage")
		{
			ContentFrame().Navigate(xaml_typename<WinUI3App::MainPage>());
		}
	}
}
