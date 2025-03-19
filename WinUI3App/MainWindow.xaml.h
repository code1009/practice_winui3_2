#pragma once

#include "MainWindow.g.h"

namespace winrt::WinUI3App::implementation
{
    struct MainWindow : MainWindowT<MainWindow>
    {
	public:
		MainWindow();
	public:
		void OnSelectionChanged(winrt::Microsoft::UI::Xaml::Controls::NavigationView const& sender, winrt::Microsoft::UI::Xaml::Controls::NavigationViewSelectionChangedEventArgs const& args);
    };
}

namespace winrt::WinUI3App::factory_implementation
{
    struct MainWindow : MainWindowT<MainWindow, implementation::MainWindow>
    {
    };
}
