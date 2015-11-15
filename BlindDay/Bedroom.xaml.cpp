//
// Bedroom.xaml.cpp
// Implementation of the Bedroom class
//

#include "pch.h"
#include "Bedroom.xaml.h"
#include "Bathroom.xaml.h"

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

int leftsock = 0;
int rightsock = 0;
int tshirt = 0;
int pants = 0;

Bedroom::Bedroom()
{
	InitializeComponent();

	//creating a new speech synthesizer object 
	this->synthesizer = ref new Windows::Media::SpeechSynthesis::SpeechSynthesizer();
}

//actual creation of the stream using the new voice synthesis stream
task<SpeechSynthesisStream ^> BlindDay::Bedroom::GetSpeechStreamTask(String ^ text)
{
	task<SpeechSynthesisStream ^>markersStream;
	markersStream = create_task(this->synthesizer->SynthesizeTextToStreamAsync(text));
	return markersStream;
}

//if media state changes to stop or pause, re-enable the speak button for audio control
void BlindDay::Bedroom::media_CurrentStateChanged(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
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

void BlindDay::Bedroom::button_PointerEntered_1(Platform::Object^ sender, Windows::UI::Xaml::Input::PointerRoutedEventArgs^ e)
{
	HRESULT hr = S_OK;
	String^ text = "That's my bed. It's probably a mess";

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


void BlindDay::Bedroom::Page_Loaded(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	HRESULT hr = S_OK;
	String^ text = "Oh, no!! I can't see a thing! Jeez! What happened to me?"
		" Right! Doctor said something about temporary blindness after lasik surgery! Ok, let's dress up and take a shower!";

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


void BlindDay::Bedroom::button1_PointerEntered_1(Platform::Object^ sender, Windows::UI::Xaml::Input::PointerRoutedEventArgs^ e)
{
	HRESULT hr = S_OK;
	String^ text = "This is something hard. This must be a wall";

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


void BlindDay::Bedroom::button2_PointerEntered_1(Platform::Object^ sender, Windows::UI::Xaml::Input::PointerRoutedEventArgs^ e)
{
	if (rightsock == 0 && leftsock == 0 && tshirt == 0 && pants == 0)
	{
		HRESULT hr = S_OK;
		String^ text = "Oh, I should go take a shower. But first I need to find my left sock, right sock, t-shirt, and pants.";

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

	else if (rightsock == 1 && leftsock == 0 && tshirt == 0 && pants == 0)
	{
		HRESULT hr = S_OK;
		String^ text = "Oh, I should go take a shower. But first I need to find my left sock, t-shirt, and pants.";

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

	else if (rightsock == 0 && leftsock == 1 && tshirt == 0 && pants == 0)
	{
		HRESULT hr = S_OK;
		String^ text = "Oh, I should go take a shower. But first I need to find my right sock, t-shirt, and pants.";

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

	else if (rightsock == 0 && leftsock == 0 && tshirt == 1 && pants == 0)
	{
		HRESULT hr = S_OK;
		String^ text = "Oh, I should go take a shower. But first I need to find my left sock, right sock, and pants.";

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

	else if (rightsock == 0 && leftsock == 0 && tshirt == 0 && pants == 1)
	{
		HRESULT hr = S_OK;
		String^ text = "Oh, I should go take a shower. But first I need to find my left sock, right sock, and t-shirt";

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

	else if (rightsock == 1 && leftsock == 1 && tshirt == 0 && pants == 0)
	{
		HRESULT hr = S_OK;
		String^ text = "Oh, I should go take a shower. But first I need to find my t-shirt and pants.";

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
	else if (rightsock == 0 && leftsock == 1 && tshirt == 1 && pants == 0)
	{
		HRESULT hr = S_OK;
		String^ text = "Oh, I should go take a shower. But first I need to find my right sock and pants.";

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
	else if (rightsock == 0 && leftsock == 0 && tshirt == 1 && pants == 1)
	{
		HRESULT hr = S_OK;
		String^ text = "Oh, I should go take a shower. But first I need to find my left sock and right sock.";

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

	else if (rightsock == 1 && leftsock == 0 && tshirt == 0 && pants == 1)
	{
		HRESULT hr = S_OK;
		String^ text = "Oh, I should go take a shower. But first I need to find my left sock and pants.";

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

	else if (rightsock == 1 && leftsock == 1 && tshirt == 1 && pants == 0)
	{
		HRESULT hr = S_OK;
		String^ text = "Oh, I should go take a shower. But first I need to find my pants.";

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

	else if (rightsock == 0 && leftsock == 1 && tshirt == 1 && pants == 1)
	{
		HRESULT hr = S_OK;
		String^ text = "Oh, I should go take a shower. But first I need to find my right sock.";

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

	else if (rightsock == 1 && leftsock == 0 && tshirt == 1 && pants == 1)
	{
		HRESULT hr = S_OK;
		String^ text = "Oh, I should go take a shower. But first I need to find my left sock.";

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

	else if (rightsock == 1 && leftsock == 1 && tshirt == 0 && pants == 1)
	{
		HRESULT hr = S_OK;
		String^ text = "Oh, I should go take a shower. But first I need to find my t-shirt.";

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
		this->Frame->Navigate(Bathroom::typeid);
	}
}


void BlindDay::Bedroom::button3_PointerEntered(Platform::Object^ sender, Windows::UI::Xaml::Input::PointerRoutedEventArgs^ e)
{
	if (rightsock == 0)
	{
		HRESULT hr = S_OK;
		String^ text = "Nice! There is my right sock.";

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


void BlindDay::Bedroom::button4_PointerEntered(Platform::Object^ sender, Windows::UI::Xaml::Input::PointerRoutedEventArgs^ e)
{
	if (leftsock == 0)
	{
		HRESULT hr = S_OK;
		String^ text = "Ok! There is my left sock.";

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


void BlindDay::Bedroom::button5_PointerEntered(Platform::Object^ sender, Windows::UI::Xaml::Input::PointerRoutedEventArgs^ e)
{
	if (tshirt == 0)
	{
		HRESULT hr = S_OK;
		String^ text = "Soft. Smelly. This is my t-shirt.";

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


void BlindDay::Bedroom::button6_PointerEntered(Platform::Object^ sender, Windows::UI::Xaml::Input::PointerRoutedEventArgs^ e)
{
	if (pants == 0)
	{
		HRESULT hr = S_OK;
		String^ text = "Long. Two trunks. There is my pants.";

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

void BlindDay::Bedroom::button7_PointerEntered(Platform::Object^ sender, Windows::UI::Xaml::Input::PointerRoutedEventArgs^ e)
{
	HRESULT hr = S_OK;
	String^ text = "This is where my window is I think. You know, I can't see a thing!";

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


void BlindDay::Bedroom::button3_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	if (rightsock == 0)
	{

		HRESULT hr = S_OK;
		String^ text = "Ok, right sock is on my right foot.";

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

		rightsock++;
	}
}


void BlindDay::Bedroom::button4_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	if (leftsock == 0)
	{

		HRESULT hr = S_OK;
		String^ text = "I'll put on my left sock.";

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

		leftsock++;
	}
}


void BlindDay::Bedroom::button5_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	if (tshirt == 0)
	{

		HRESULT hr = S_OK;
		String^ text = "I'll put on my tshirt.";

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

		tshirt++;
	}
}


void BlindDay::Bedroom::button6_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	if (pants == 0)
	{

		HRESULT hr = S_OK;
		String^ text = "I'll put on my pants.";

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

		pants++;
	}
}
