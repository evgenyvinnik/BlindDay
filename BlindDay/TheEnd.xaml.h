//
// TheEnd.xaml.h
// Declaration of the TheEnd class
//

#pragma once

#include "TheEnd.g.h"
using namespace Windows::Media::SpeechSynthesis;
using namespace Platform;


namespace BlindDay
{
	/// <summary>
	/// An empty page that can be used on its own or navigated to within a Frame.
	/// </summary>
	public ref class TheEnd sealed
	{
	public:
		TheEnd();
	private:
		void media_CurrentStateChanged(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
		// this function will make the call to the speech synthesis engine, and determine
		// if it should use the SSML or Text implementation
		Concurrency::task<SpeechSynthesisStream ^> BlindDay::TheEnd::GetSpeechStreamTask(String ^ text);

		// private member
		Windows::Media::SpeechSynthesis::SpeechSynthesizer^ synthesizer;
		void Grid_Loaded(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
		void button_PointerEntered(Platform::Object^ sender, Windows::UI::Xaml::Input::PointerRoutedEventArgs^ e);
		void button_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
	};
}
