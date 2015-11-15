//
// Bathroom_1.xaml.cpp
// Implementation of the Bathroom class
//

#include "pch.h"
#include "Bathroom.xaml.h"
#include "Breakfast.xaml.h"

using namespace BlindDay;

using namespace Windows::UI::Xaml;
using namespace Windows::UI::Xaml::Controls;
using namespace Platform;
using namespace Platform::Collections;
using namespace Concurrency;
using namespace Windows::Data::Xml::Dom;
using namespace Windows::Foundation;
using namespace Windows::Foundation::Collections;
using namespace Windows::Storage;
using namespace Windows::Storage::BulkAccess;
using namespace Windows::Storage::Pickers;
using namespace Windows::Storage::Streams;
using namespace Windows::UI::Xaml::Controls::Primitives;
using namespace Windows::UI::Xaml::Data;
using namespace Windows::UI::Xaml::Input;
using namespace Windows::UI::Xaml::Media;
using namespace Windows::UI::Xaml::Navigation;
using namespace Windows::Media::SpeechSynthesis;

int Toothbrush = 0;
int Toothpaste = 0;
int Hot_tap = 0;
int Cold_tap = 0;
int Mirror = 0;
int Towel = 0;
int Razor = 0;
int Sink = 0;


// The Blank Page item template is documented at http://go.microsoft.com/fwlink/?LinkId=234238

Bathroom::Bathroom()
{
	InitializeComponent();

	//creating a new speech synthesizer object 
	this->synthesizer = ref new Windows::Media::SpeechSynthesis::SpeechSynthesizer();
}

//actual creation of the stream using the new voice synthesis stream
task<SpeechSynthesisStream ^> BlindDay::Bathroom::GetSpeechStreamTask(String ^ text)
{
	task<SpeechSynthesisStream ^>markersStream;
	markersStream = create_task(this->synthesizer->SynthesizeTextToStreamAsync(text));
	return markersStream;
}


//if media state changes to stop or pause, re-enable the speak button for audio control
void BlindDay::Bathroom::media_CurrentStateChanged(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	MediaElement ^element = (MediaElement ^)sender;

	if (element->CurrentState == MediaElementState::Stopped ||
		element->CurrentState == MediaElementState::Paused)
	{
		MediaElement ^element = (MediaElement ^)sender;

		if (element->CurrentState == MediaElementState::Stopped ||
			element->CurrentState == MediaElementState::Paused)
		{
			this->button->IsEnabled = true;
			this->button1->IsEnabled = true;
			this->button2->IsEnabled = true;
			this->button3->IsEnabled = true;
			this->button4->IsEnabled = true;
			this->button5->IsEnabled = true;
			this->button6->IsEnabled = true;
			this->button7->IsEnabled = true;
		}
	}
}
void BlindDay::Bathroom::button_PointerEntered(Platform::Object^ sender, Windows::UI::Xaml::Input::PointerRoutedEventArgs^ e)
{
	if (Toothpaste == 0)
	{
		HRESULT hr = S_OK;
		String^ text = "Here is the toothpaste.";

		try
		{
			auto speakTask = this->GetSpeechStreamTask(text);
			speakTask.then([this, text](SpeechSynthesisStream ^speechStream)
			{
				// start this audio stream playing
				this->media->SetSource(speechStream, speechStream->ContentType);
				this->media->AutoPlay = true;
				this->media->Play();

			});
		}
		catch (Exception ^ex)
		{
			hr = ex->HResult;

		}
	}
}


void BlindDay::Bathroom::button1_PointerEntered(Platform::Object^ sender, Windows::UI::Xaml::Input::PointerRoutedEventArgs^ e)
{
	if (Toothbrush == 0)
	{
		HRESULT hr = S_OK;
		String^ text = "Toothbrush, toothepaste, and water at the sink is all I need in here";

		try
		{
			auto speakTask = this->GetSpeechStreamTask(text);
			speakTask.then([this, text](SpeechSynthesisStream ^speechStream)
			{
				// start this audio stream playing
				this->media->SetSource(speechStream, speechStream->ContentType);
				this->media->AutoPlay = true;
				this->media->Play();

			});
		}
		catch (Exception ^ex)
		{
			hr = ex->HResult;

		}
	}
}


void BlindDay::Bathroom::button2_PointerEntered(Platform::Object^ sender, Windows::UI::Xaml::Input::PointerRoutedEventArgs^ e)
{
	if (Razor == 0)
	{
		HRESULT hr = S_OK;
		String^ text = "Razor, should not be used now!";

		try
		{
			auto speakTask = this->GetSpeechStreamTask(text);
			speakTask.then([this, text](SpeechSynthesisStream ^speechStream)
			{
				// start this audio stream playing
				this->media->SetSource(speechStream, speechStream->ContentType);
				this->media->AutoPlay = true;
				this->media->Play();

			});
		}
		catch (Exception ^ex)
		{
			hr = ex->HResult;

		}
	}
}

void BlindDay::Bathroom::button3_PointerEntered(Platform::Object^ sender, Windows::UI::Xaml::Input::PointerRoutedEventArgs^ e)
{
	if (Hot_tap == 0)
	{
		HRESULT hr = S_OK;
		String^ text = "One of the water tap is here, the other one should close by";

		try
		{
			auto speakTask = this->GetSpeechStreamTask(text);
			speakTask.then([this, text](SpeechSynthesisStream ^speechStream)
			{
				// start this audio stream playing
				this->media->SetSource(speechStream, speechStream->ContentType);
				this->media->AutoPlay = true;
				this->media->Play();

			});
		}
		catch (Exception ^ex)
		{
			hr = ex->HResult;


		}
	}
}

void BlindDay::Bathroom::button4_PointerEntered(Platform::Object^ sender, Windows::UI::Xaml::Input::PointerRoutedEventArgs^ e)
{
	if (Cold_tap == 0)
	{
		HRESULT hr = S_OK;
		String^ text = "Here is the cold water tap.";

		try
		{
			auto speakTask = this->GetSpeechStreamTask(text);
			speakTask.then([this, text](SpeechSynthesisStream ^speechStream)
			{
				// start this audio stream playing
				this->media->SetSource(speechStream, speechStream->ContentType);
				this->media->AutoPlay = true;
				this->media->Play();

			});
		}
		catch (Exception ^ex)
		{
			hr = ex->HResult;

		}
	}
}

void BlindDay::Bathroom::button5_PointerEntered(Platform::Object^ sender, Windows::UI::Xaml::Input::PointerRoutedEventArgs^ e)
{
	if (Sink == 0)
	{
		HRESULT hr = S_OK;
		String^ text = "I need to brush my teeth, I need toothpaste, toothbrush, hot water tap, and cold water tap.";
		try
		{
			auto speakTask = this->GetSpeechStreamTask(text);
			speakTask.then([this, text](SpeechSynthesisStream ^speechStream)
			{
				// start this audio stream playing
				this->media->SetSource(speechStream, speechStream->ContentType);
				this->media->AutoPlay = true;
				this->media->Play();
			});
		}
		catch (Exception ^ex)
		{
			hr = ex->HResult;
		}
	}
}


void BlindDay::Bathroom::button6_PointerEntered(Platform::Object^ sender, Windows::UI::Xaml::Input::PointerRoutedEventArgs^ e)
{
	if (Towel == 0)
	{
		HRESULT hr = S_OK;
		String^ text = "I can use towel later.";

		try
		{
			auto speakTask = this->GetSpeechStreamTask(text);
			speakTask.then([this, text](SpeechSynthesisStream ^speechStream)
			{
				// start this audio stream playing
				this->media->SetSource(speechStream, speechStream->ContentType);
				this->media->AutoPlay = true;
				this->media->Play();

			});
		}
		catch (Exception ^ex)
		{
			hr = ex->HResult;

		}
	}

}

void BlindDay::Bathroom::button7_PointerEntered(Platform::Object^ sender, Windows::UI::Xaml::Input::PointerRoutedEventArgs^ e)
{
	if (Mirror == 0)
	{
		HRESULT hr = S_OK;
		String^ text = "I wish I could see myself now in the mirror";

		try
		{
			auto speakTask = this->GetSpeechStreamTask(text);
			speakTask.then([this, text](SpeechSynthesisStream ^speechStream)
			{
				// start this audio stream playing
				this->media->SetSource(speechStream, speechStream->ContentType);
				this->media->AutoPlay = true;
				this->media->Play();

			});
		}
		catch (Exception ^ex)
		{
			hr = ex->HResult;

		}
	}
}


void BlindDay::Bathroom::button_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	String^ first_touch = "I got the toothpaste, I am looking for toothbrush";
	String^ second_touch = "I already have toothpaste in my hand";
	String^ third_touch = "I don't need toothpaste anymore";
	if (Toothpaste == 0)
	{
		HRESULT hr = S_OK;
		try
		{
			auto speakTask = this->GetSpeechStreamTask(first_touch);
			speakTask.then([this, first_touch](SpeechSynthesisStream ^speechStream)
			{
				// start this audio stream playing
				this->media->SetSource(speechStream, speechStream->ContentType);
				this->media->AutoPlay = true;
				this->media->Play();

			});
		}
		catch (Exception ^ex)
		{
			hr = ex->HResult;

		}

		Toothpaste++;
	}

	else if (Toothpaste == 1)
	{

		HRESULT hr = S_OK;

		try
		{
			auto speakTask = this->GetSpeechStreamTask(second_touch);
			speakTask.then([this, second_touch](SpeechSynthesisStream ^speechStream)
			{
				// start this audio stream playing
				this->media->SetSource(speechStream, speechStream->ContentType);
				this->media->AutoPlay = true;
				this->media->Play();

			});
		}
		catch (Exception ^ex)
		{
			hr = ex->HResult;

		}

		Toothpaste++;
	}

	else if (Toothpaste >= 2)
	{

		HRESULT hr = S_OK;

		try
		{
			auto speakTask = this->GetSpeechStreamTask(third_touch);
			speakTask.then([this, third_touch](SpeechSynthesisStream ^speechStream)
			{
				// start this audio stream playing
				this->media->SetSource(speechStream, speechStream->ContentType);
				this->media->AutoPlay = true;
				this->media->Play();

			});
		}
		catch (Exception ^ex)
		{
			hr = ex->HResult;

		}

		Toothpaste++;
	}
}

void BlindDay::Bathroom::button1_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{

	String^ first_touch = "I got the toothbrush, I need both hot and cold tap for the water";
	String^ second_touch = "I think I brush my teeth";
	String^ third_touch = "My teeth are glowing in the dark";

		if (Toothbrush == 0)
		{
			HRESULT hr = S_OK;
			try
			{
				auto speakTask = this->GetSpeechStreamTask(first_touch);
				speakTask.then([this, first_touch](SpeechSynthesisStream ^speechStream)
				{
					// start this audio stream playing
					this->media->SetSource(speechStream, speechStream->ContentType);
					this->media->AutoPlay = true;
					this->media->Play();

				});
			}
			catch (Exception ^ex)
			{
				hr = ex->HResult;

			}

			Toothbrush++;
		}

		else if(Toothbrush == 1)
		{

			HRESULT hr = S_OK;

			try
			{
				auto speakTask = this->GetSpeechStreamTask(second_touch);
				speakTask.then([this, second_touch](SpeechSynthesisStream ^speechStream)
				{
					// start this audio stream playing
					this->media->SetSource(speechStream, speechStream->ContentType);
					this->media->AutoPlay = true;
					this->media->Play();

				});
			}
			catch (Exception ^ex)
			{
				hr = ex->HResult;

			}

			Toothbrush++;
		}

		else if (Toothbrush >= 2)
		{

			HRESULT hr = S_OK;

			try
			{
				auto speakTask = this->GetSpeechStreamTask(third_touch);
				speakTask.then([this, third_touch](SpeechSynthesisStream ^speechStream)
				{
					// start this audio stream playing
					this->media->SetSource(speechStream, speechStream->ContentType);
					this->media->AutoPlay = true;
					this->media->Play();

				});
			}
			catch (Exception ^ex)
			{
				hr = ex->HResult;

			}

			Toothbrush++;
		}
}
void BlindDay::Bathroom::button2_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	String^ first_touch = "I don't think it is a good idea to razor";
	String^ second_touch = "I need some assitance using the razor";
	String^ third_touch = "It is not a good idea to do this alone";
	if (Razor == 0)
	{
		HRESULT hr = S_OK;
		try
		{
			auto speakTask = this->GetSpeechStreamTask(first_touch);
			speakTask.then([this, first_touch](SpeechSynthesisStream ^speechStream)
			{
				// start this audio stream playing
				this->media->SetSource(speechStream, speechStream->ContentType);
				this->media->AutoPlay = true;
				this->media->Play();

			});
		}
		catch (Exception ^ex)
		{
			hr = ex->HResult;

		}

		Razor++;
	}

	else if (Razor == 1)
	{

		HRESULT hr = S_OK;

		try
		{
			auto speakTask = this->GetSpeechStreamTask(second_touch);
			speakTask.then([this, second_touch](SpeechSynthesisStream ^speechStream)
			{
				// start this audio stream playing
				this->media->SetSource(speechStream, speechStream->ContentType);
				this->media->AutoPlay = true;
				this->media->Play();

			});
		}
		catch (Exception ^ex)
		{
			hr = ex->HResult;

		}

		Razor++;
	}

	else if (Razor >= 2)
	{

		HRESULT hr = S_OK;

		try
		{
			auto speakTask = this->GetSpeechStreamTask(third_touch);
			speakTask.then([this, third_touch](SpeechSynthesisStream ^speechStream)
			{
				// start this audio stream playing
				this->media->SetSource(speechStream, speechStream->ContentType);
				this->media->AutoPlay = true;
				this->media->Play();

			});
		}
		catch (Exception ^ex)
		{
			hr = ex->HResult;

		}

		Razor++;
	}
}

void BlindDay::Bathroom::button3_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{

	String^ first_touch = "Nice, hot water";
	String^ second_touch = "It is too hot, where is the cold water tap";
	String^ third_touch = "Ouch, I am buring my skin";

		if (Hot_tap == 0)
		{
			HRESULT hr = S_OK;
			try
			{
				auto speakTask = this->GetSpeechStreamTask(first_touch);
				speakTask.then([this, first_touch](SpeechSynthesisStream ^speechStream)
				{
					// start this audio stream playing
					this->media->SetSource(speechStream, speechStream->ContentType);
					this->media->AutoPlay = true;
					this->media->Play();

				});
			}
			catch (Exception ^ex)
			{
				hr = ex->HResult;

			}

			Hot_tap++;
		}

		else if (Hot_tap == 1)
		{

			HRESULT hr = S_OK;

			try
			{
				auto speakTask = this->GetSpeechStreamTask(second_touch);
				speakTask.then([this, second_touch](SpeechSynthesisStream ^speechStream)
				{
					// start this audio stream playing
					this->media->SetSource(speechStream, speechStream->ContentType);
					this->media->AutoPlay = true;
					this->media->Play();

				});
			}
			catch (Exception ^ex)
			{
				hr = ex->HResult;

			}

			Hot_tap++;
		}

		else if (Hot_tap >= 2)
		{

			HRESULT hr = S_OK;

			try
			{
				auto speakTask = this->GetSpeechStreamTask(third_touch);
				speakTask.then([this, third_touch](SpeechSynthesisStream ^speechStream)
				{
					// start this audio stream playing
					this->media->SetSource(speechStream, speechStream->ContentType);
					this->media->AutoPlay = true;
					this->media->Play();

				});
			}
			catch (Exception ^ex)
			{
				hr = ex->HResult;

			}

			Hot_tap++;
		}
}


void BlindDay::Bathroom::button4_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{		
		String^ first_touch = "Nice and cold";
		String^ second_touch = "Did I get the warm water tap";
		String^ third_touch = "This is too cold, where is warm water tap";
	if (Cold_tap == 0)
	{
		HRESULT hr = S_OK;
		try
		{
			auto speakTask = this->GetSpeechStreamTask(first_touch);
			speakTask.then([this, first_touch](SpeechSynthesisStream ^speechStream)
			{
				// start this audio stream playing
				this->media->SetSource(speechStream, speechStream->ContentType);
				this->media->AutoPlay = true;
				this->media->Play();

			});
		}
		catch (Exception ^ex)
		{
			hr = ex->HResult;

		}

		Cold_tap++;
	}

	else if (Cold_tap == 1)
	{

		HRESULT hr = S_OK;

		try
		{
			auto speakTask = this->GetSpeechStreamTask(second_touch);
			speakTask.then([this, second_touch ](SpeechSynthesisStream ^speechStream)
			{
				// start this audio stream playing
				this->media->SetSource(speechStream, speechStream->ContentType);
				this->media->AutoPlay = true;
				this->media->Play();

			});
		}
		catch (Exception ^ex)
		{
			hr = ex->HResult;

		}

		Cold_tap++;
	}

	else if (Cold_tap >= 2)
	{

		HRESULT hr = S_OK;

		try
		{
			auto speakTask = this->GetSpeechStreamTask(third_touch);
			speakTask.then([this, third_touch](SpeechSynthesisStream ^speechStream)
			{
				// start this audio stream playing
				this->media->SetSource(speechStream, speechStream->ContentType);
				this->media->AutoPlay = true;
				this->media->Play();

			});
		}
		catch (Exception ^ex)
		{
			hr = ex->HResult;

		}

		Cold_tap++;
	}
}

void BlindDay::Bathroom::button5_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	HRESULT hr = S_OK;
	String^ first_touch = "I found the sink, cold and hot water tap should be close by.";
	String^ second_touch = "I am still looking for the water tap.";
	String^ third_touch = "I found nothing useful in the sink.";
	if (Sink == 0)
	{
		if (Toothpaste >= 1 && Toothpaste >= 1 && Hot_tap >= 1 && Cold_tap >= 1 && Sink >= 1)
		{
			this->Frame->Navigate(Breakfast::typeid);
		}
		HRESULT hr = S_OK;
		try
		{
			auto speakTask = this->GetSpeechStreamTask(first_touch);
			speakTask.then([this, first_touch](SpeechSynthesisStream ^speechStream)
			{
				// start this audio stream playing
				this->media->SetSource(speechStream, speechStream->ContentType);
				this->media->AutoPlay = true;
				this->media->Play();

			});
		}
		catch (Exception ^ex)
		{
			hr = ex->HResult;

		}

		Sink++;
	}

	else if (Sink == 1)
	{
		if (Toothpaste >= 1 && Toothpaste >= 1 && Hot_tap >= 1 && Cold_tap >= 1)
		{
			this->Frame->Navigate(Breakfast::typeid);
		}

		HRESULT hr = S_OK;

		try
		{
			auto speakTask = this->GetSpeechStreamTask(second_touch);
			speakTask.then([this, second_touch](SpeechSynthesisStream ^speechStream)
			{
				// start this audio stream playing
				this->media->SetSource(speechStream, speechStream->ContentType);
				this->media->AutoPlay = true;
				this->media->Play();

			});
		}
		catch (Exception ^ex)
		{
			hr = ex->HResult;

		}

		Sink++;
	}

	else if (Sink >= 2)
	{
		 if (Toothpaste >= 1 && Toothpaste >= 1 && Hot_tap >= 1 && Cold_tap >= 1 && Sink >= 1)
	    {
		    this->Frame->Navigate(Breakfast::typeid);
		}

		HRESULT hr = S_OK;

		try
		{
			auto speakTask = this->GetSpeechStreamTask(third_touch);
			speakTask.then([this, third_touch](SpeechSynthesisStream ^speechStream)
			{
				// start this audio stream playing
				this->media->SetSource(speechStream, speechStream->ContentType);
				this->media->AutoPlay = true;
				this->media->Play();

			});
		}
		catch (Exception ^ex)
		{
			hr = ex->HResult;

		}

		Sink++;
	}
}

void BlindDay::Bathroom::button6_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	HRESULT hr = S_OK;
	String^ first_touch = "I should dry my hand with this towel later.";
	String^ second_touch = "I know where the towel is.";
	String^ third_touch = "I don't need the towel now.";
	if (Towel== 0)
	{
		HRESULT hr = S_OK;
		try
		{
			auto speakTask = this->GetSpeechStreamTask(first_touch);
			speakTask.then([this, first_touch](SpeechSynthesisStream ^speechStream)
			{
				// start this audio stream playing
				this->media->SetSource(speechStream, speechStream->ContentType);
				this->media->AutoPlay = true;
				this->media->Play();

			});
		}
		catch (Exception ^ex)
		{
			hr = ex->HResult;

		}

		Towel++;
	}

	else if (Towel == 1)
	{

		HRESULT hr = S_OK;

		try
		{
			auto speakTask = this->GetSpeechStreamTask(second_touch);
			speakTask.then([this, second_touch](SpeechSynthesisStream ^speechStream)
			{
				// start this audio stream playing
				this->media->SetSource(speechStream, speechStream->ContentType);
				this->media->AutoPlay = true;
				this->media->Play();

			});
		}
		catch (Exception ^ex)
		{
			hr = ex->HResult;

		}

		Towel++;
	}

	else if (Towel >= 2)
	{

		HRESULT hr = S_OK;

		try
		{
			auto speakTask = this->GetSpeechStreamTask(third_touch);
			speakTask.then([this, third_touch](SpeechSynthesisStream ^speechStream)
			{
				// start this audio stream playing
				this->media->SetSource(speechStream, speechStream->ContentType);
				this->media->AutoPlay = true;
				this->media->Play();

			});
		}
		catch (Exception ^ex)
		{
			hr = ex->HResult;

		}

		Towel++;
	}
}

void BlindDay::Bathroom::button7_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	String^ first_touch = "I can't see myself in the dark with the mirror";
	String^ second_touch = "I don't think mirror help at all";
	String^ third_touch = "I bet I look good, but I cannot see myself in the dark";
	if (Mirror == 0)
	{
		HRESULT hr = S_OK;
		try
		{
			auto speakTask = this->GetSpeechStreamTask(first_touch);
			speakTask.then([this, first_touch](SpeechSynthesisStream ^speechStream)
			{
				// start this audio stream playing
				this->media->SetSource(speechStream, speechStream->ContentType);
				this->media->AutoPlay = true;
				this->media->Play();

			});
		}
		catch (Exception ^ex)
		{
			hr = ex->HResult;

		}

		Mirror++;
	}

	else if (Mirror == 1)
	{

		HRESULT hr = S_OK;

		try
		{
			auto speakTask = this->GetSpeechStreamTask(second_touch);
			speakTask.then([this, second_touch](SpeechSynthesisStream ^speechStream)
			{
				// start this audio stream playing
				this->media->SetSource(speechStream, speechStream->ContentType);
				this->media->AutoPlay = true;
				this->media->Play();

			});
		}
		catch (Exception ^ex)
		{
			hr = ex->HResult;

		}

		Mirror++;
	}

	else if (Mirror >= 2)
	{

		HRESULT hr = S_OK;

		try
		{
			auto speakTask = this->GetSpeechStreamTask(third_touch);
			speakTask.then([this, third_touch](SpeechSynthesisStream ^speechStream)
			{
				// start this audio stream playing
				this->media->SetSource(speechStream, speechStream->ContentType);
				this->media->AutoPlay = true;
				this->media->Play();

			});
		}
		catch (Exception ^ex)
		{
			hr = ex->HResult;

		}

		Mirror++;
	}
}

