//
// Breakfast.xaml.h
// Declaration of the Breakfast class
//

#pragma once

#include "Breakfast.g.h"

namespace BlindDay
{
	/// <summary>
	/// An empty page that can be used on its own or navigated to within a Frame.
	/// </summary>
	[Windows::Foundation::Metadata::WebHostHidden]
	public ref class Breakfast sealed
	{
	public:
		Breakfast();
	private:
		void Grid_Loaded(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
	};
}
