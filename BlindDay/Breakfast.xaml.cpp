//
// Breakfast.xaml.cpp
// Implementation of the Breakfast class
//

#include "pch.h"
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

// The Blank Page item template is documented at http://go.microsoft.com/fwlink/?LinkId=234238

int waffles = 0;
int milk = 0;
int tealeaves = 0;
int teapot = 0;
int cup = 0;
int brew = 0;
int toaster = 0;

Breakfast::Breakfast()
{
	InitializeComponent();

	//creating a new speech synthesizer object 
	this->synthesizer = ref new Windows::Media::SpeechSynthesis::SpeechSynthesizer();
}

//actual creation of the stream using the new voice synthesis stream
task<SpeechSynthesisStream ^> BlindDay::Breakfast::GetSpeechStreamTask(String ^ text)
{
	task<SpeechSynthesisStream ^>markersStream;
	markersStream = create_task(this->synthesizer->SynthesizeTextToStreamAsync(text));
	return markersStream;
}

//if media state changes to stop or pause, re-enable the speak button for audio control
void BlindDay::Breakfast::media_CurrentStateChanged(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	MediaElement ^element = (MediaElement ^)sender;

	if (element->CurrentState == MediaElementState::Stopped ||
		element->CurrentState == MediaElementState::Paused)
	{
		//this->btnSpeak->IsEnabled = true;
	}
}


void BlindDay::Breakfast::Grid_Loaded(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	HRESULT hr = S_OK;
	String^ text = "It would be nice to eat something. I think I want some waffles with milk tea.";

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


void BlindDay::Breakfast::button_PointerEntered(Platform::Object^ sender, Windows::UI::Xaml::Input::PointerRoutedEventArgs^ e)
{
	if (waffles == 0)
	{
		HRESULT hr = S_OK;
		String^ text = "This is the freezer, I think I have some waffles in it.";

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
	else
	{
		HRESULT hr = S_OK;
		String^ text = "This is the freezer.";

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


void BlindDay::Breakfast::button_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	if (waffles == 0)
	{
		HRESULT hr = S_OK;
		String^ text = "I think I will grab some waffles.";

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
		waffles++;
	}
}


void BlindDay::Breakfast::button1_PointerEntered(Platform::Object^ sender, Windows::UI::Xaml::Input::PointerRoutedEventArgs^ e)
{
	if (toaster == 0)
	{
		HRESULT hr = S_OK;
		String^ text = "This is the toaster, I think I can toast my waffles in it.";

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
	else
	{
		HRESULT hr = S_OK;
		String^ text = "This is the toaster.";

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


void BlindDay::Breakfast::button1_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	if (waffles == 1 && toaster == 0)
	{
		HRESULT hr = S_OK;
		String^ text = "I'll toast my waffles right now.";

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
		toaster++;
	}
	else
	{
		HRESULT hr = S_OK;
		String^ text = "I need my waffles to use to toaster.";

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


void BlindDay::Breakfast::button2_PointerEntered(Platform::Object^ sender, Windows::UI::Xaml::Input::PointerRoutedEventArgs^ e)
{
	if (milk == 0)
	{
		HRESULT hr = S_OK;
		String^ text = "This is the fridge, I think there is milk in it.";

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
	else
	{
		HRESULT hr = S_OK;
		String^ text = "This is the fridge.";

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


void BlindDay::Breakfast::button2_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	if (milk == 0)
	{
		HRESULT hr = S_OK;
		String^ text = "I think I'll grab some milk.";

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
		milk++;
	}
}

void BlindDay::Breakfast::button3_PointerEntered(Platform::Object^ sender, Windows::UI::Xaml::Input::PointerRoutedEventArgs^ e)
{
	HRESULT hr = S_OK;
	String^ text = "This is the dinning table. I can eat here after I get my waffles and milk tea.";

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


void BlindDay::Breakfast::button3_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	if (milk == 1 && teapot == 1 && tealeaves == 1 && waffles == 1 && toaster == 1 && cup == 1 && brew == 1)
	{
		HRESULT hr = S_OK;
		String^ text = "I think I'll eat now.";

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
		App::Current->Exit();
	}
}


void BlindDay::Breakfast::button5_PointerEntered(Platform::Object^ sender, Windows::UI::Xaml::Input::PointerRoutedEventArgs^ e)
{
	if (cup == 0)
	{
		HRESULT hr = S_OK;
		String^ text = "There is my cup. Perfect for tea.";

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


void BlindDay::Breakfast::button5_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	if (cup == 0)
	{
		HRESULT hr = S_OK;
		String^ text = "I'll drink tea out of this.";

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
		cup++;
	}
}


void BlindDay::Breakfast::button6_PointerEntered(Platform::Object^ sender, Windows::UI::Xaml::Input::PointerRoutedEventArgs^ e)
{
	if (tealeaves == 0)
	{
		HRESULT hr = S_OK;
		String^ text = "This feels like my green tea box set.";

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
	else
	{
		HRESULT hr = S_OK;
		String^ text = "My green tea box set.";

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


void BlindDay::Breakfast::button6_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	if (tealeaves == 0)
	{
		HRESULT hr = S_OK;
		String^ text = "I think I'll take some tea leaves.";

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
		tealeaves++;
	}
}


void BlindDay::Breakfast::button7_PointerEntered(Platform::Object^ sender, Windows::UI::Xaml::Input::PointerRoutedEventArgs^ e)
{
	if (teapot == 0)
	{
		HRESULT hr = S_OK;
		String^ text = "My tea pot. I can use this to brew tea.";

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


void BlindDay::Breakfast::button7_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	if (teapot == 0)
	{
		HRESULT hr = S_OK;
		String^ text = "I'll take my teapot so I can brew my tea.";

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
		teapot++;
	}
}


void BlindDay::Breakfast::button8_PointerEntered(Platform::Object^ sender, Windows::UI::Xaml::Input::PointerRoutedEventArgs^ e)
{
	if (cup == 0 && teapot == 0 && tealeaves == 0)
	{
		HRESULT hr = S_OK;
		String^ text = "The kitchen sink and stove. I can use this to brew tea if I had a cup, teapot and some tealeaves.";

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
	else if (cup == 1 && teapot == 0 && tealeaves == 0)
	{
		HRESULT hr = S_OK;
		String^ text = "The kitchen sink and stove. I can use this to brew tea if I had a teapot and some tealeaves.";

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
	else if (cup == 0 && teapot == 1 && tealeaves == 0)
	{
		HRESULT hr = S_OK;
		String^ text = "The kitchen sink and stove. I can use this to brew tea if I had a cup and some tealeaves.";

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
	else if (cup == 0 && teapot == 0 && tealeaves == 1)
	{
		HRESULT hr = S_OK;
		String^ text = "The kitchen sink and stove. I can use this to brew tea if I had a teapot and a cup.";

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
	else if (cup == 1 && teapot == 1 && tealeaves == 0)
	{
		HRESULT hr = S_OK;
		String^ text = "The kitchen sink and stove. I can use this to brew tea if I had some tealeaves.";

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
	else if (cup == 0 && teapot == 1 && tealeaves == 1)
	{
		HRESULT hr = S_OK;
		String^ text = "The kitchen sink and stove. I can use this to brew tea if I had a cup.";

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
	else if (cup == 1 && teapot == 0 && tealeaves == 1)
	{
		HRESULT hr = S_OK;
		String^ text = "The kitchen sink and stove. I can use this to brew tea if I had a teapot.";

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
	else if (cup == 1 && teapot == 1 && tealeaves == 1)
	{
		HRESULT hr = S_OK;
		String^ text = "The kitchen sink and stove. I can use this to brew tea.";

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
	else
	{
	}
}


void BlindDay::Breakfast::button8_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	if (cup == 1 && teapot == 1 && tealeaves == 1 && milk == 0 && brew == 0)
	{
		HRESULT hr = S_OK;
		String^ text = "I'll brew some tea now. I only need milk now to make it a milk tea.";

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
		brew++;
	}
	else if (cup == 1 && teapot == 1 && tealeaves == 1 && milk == 1 && brew == 0)
	{
		HRESULT hr = S_OK;
		String^ text = "I'll brew some tea now. Can't wait for my milk tea.";

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
		brew++;
	}
	else
	{
		HRESULT hr = S_OK;
		String^ text = "I need to find the right things to brew tea.";

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
