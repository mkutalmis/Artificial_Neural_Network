#pragma once
#include"ActivationFunctions.h"
#include"CostFunctions.h"
#include"Optimizer.h"
#include"Neuron.h"
#include"Layer.h"
#include"Network.h"

namespace ANN {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent(); 
			Control::CheckForIllegalCrossThreadCalls = false;
			this->class_count = 0;
			this->data_count = 0;
			this->step1 = false;
			this->step2 = false;
			this->step3 = false;
			Bitmap^ initBitmap = gcnew Bitmap(this->pictureBox1->Width, this->pictureBox1->Height);
			for (int i = 0; i < this->pictureBox1->Width; i++)
			{
				for (int j = 0; j < this->pictureBox1->Height; j++)
				{
					initBitmap->SetPixel(i, j, Color::White);
				}
			}
			this->pictureBox1->Image = initBitmap;
			this->actFunc = gcnew ActivationFunctions();
			this->costFunc = gcnew CostFunctions();
			this->opt = gcnew Optimizer();
			this->means = new double[10];
			this->std_deviations = new double[10];
			for each (System::String^ activationFunctions in actFunc->get_names())
			{
				this->comboBox3->Items->Add(activationFunctions);
			}
			for each (System::String^ costFunctions in costFunc->get_names())
			{
				this->comboBox4->Items->Add(costFunctions);
			}
			for each (System::String^ optimizer in opt->get_names())
			{
				this->comboBox5->Items->Add(optimizer);
			}

		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::PictureBox^  pictureBox1;
	protected:
	private: System::Windows::Forms::ListView^  listView1;
	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::TextBox^  classCount_textbox;

	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::ComboBox^  comboBox1;



	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Button^  button4;
	private: System::Windows::Forms::TextBox^  textBox3;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::ComboBox^  comboBox2;
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::ListView^  listView2;
	private: System::Windows::Forms::Label^  label8;
	private: System::Windows::Forms::ComboBox^  comboBox3;
	private: System::Windows::Forms::Label^  label9;
	private: System::Windows::Forms::ComboBox^  comboBox4;
	private: System::Windows::Forms::Label^  label10;
	private: System::Windows::Forms::ComboBox^  comboBox5;
	private: System::Windows::Forms::Button^  button5;
	private: System::Windows::Forms::Button^  button6;
	private: System::Windows::Forms::Label^  label11;
	private: System::Windows::Forms::ListView^  listView3;
	private: System::Windows::Forms::Label^  label13;
	private: System::Windows::Forms::ComboBox^  comboBox6;
	private: System::Windows::Forms::Label^  label12;
	private: System::Windows::Forms::Label^  label14;
	private: System::Windows::Forms::Label^  label15;
	private: System::Windows::Forms::Label^  label16;
	private: System::Windows::Forms::Label^  label17;
	private: System::Windows::Forms::Label^  label18;
	private: System::Windows::Forms::Label^  label19;
	private: System::Windows::Forms::TextBox^  textBox4;
	private: System::Windows::Forms::Label^  label20;
	private: System::Windows::Forms::Label^  label21;
	private: System::Windows::Forms::Label^  label22;
	private: System::Windows::Forms::TextBox^  textBox5;
	private: System::Windows::Forms::Button^  button7;
	private: System::Windows::Forms::Label^  label23;
	private: System::Windows::Forms::Label^  label24;
	private: System::Windows::Forms::Label^  label25;
	private: System::Windows::Forms::Label^  label26;
	private: System::Windows::Forms::Label^  label27;

	private: System::Windows::Forms::ColorDialog^  colorDialog1;
private: System::Windows::Forms::Button^  button8;
private: System::Windows::Forms::TextBox^  textBox2;
private: System::Windows::Forms::Label^  label28;

private: System::Windows::Forms::Button^  button9;


	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->listView1 = (gcnew System::Windows::Forms::ListView());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->classCount_textbox = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->comboBox2 = (gcnew System::Windows::Forms::ComboBox());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->listView2 = (gcnew System::Windows::Forms::ListView());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->comboBox3 = (gcnew System::Windows::Forms::ComboBox());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->comboBox4 = (gcnew System::Windows::Forms::ComboBox());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->comboBox5 = (gcnew System::Windows::Forms::ComboBox());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->listView3 = (gcnew System::Windows::Forms::ListView());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->comboBox6 = (gcnew System::Windows::Forms::ComboBox());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->label14 = (gcnew System::Windows::Forms::Label());
			this->label15 = (gcnew System::Windows::Forms::Label());
			this->label16 = (gcnew System::Windows::Forms::Label());
			this->label17 = (gcnew System::Windows::Forms::Label());
			this->label18 = (gcnew System::Windows::Forms::Label());
			this->label19 = (gcnew System::Windows::Forms::Label());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->label20 = (gcnew System::Windows::Forms::Label());
			this->label21 = (gcnew System::Windows::Forms::Label());
			this->label22 = (gcnew System::Windows::Forms::Label());
			this->textBox5 = (gcnew System::Windows::Forms::TextBox());
			this->button7 = (gcnew System::Windows::Forms::Button());
			this->label23 = (gcnew System::Windows::Forms::Label());
			this->label24 = (gcnew System::Windows::Forms::Label());
			this->label25 = (gcnew System::Windows::Forms::Label());
			this->label26 = (gcnew System::Windows::Forms::Label());
			this->label27 = (gcnew System::Windows::Forms::Label());
			this->colorDialog1 = (gcnew System::Windows::Forms::ColorDialog());
			this->button8 = (gcnew System::Windows::Forms::Button());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->label28 = (gcnew System::Windows::Forms::Label());
			this->button9 = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// pictureBox1
			// 
			this->pictureBox1->BackColor = System::Drawing::SystemColors::ControlLight;
			this->pictureBox1->Location = System::Drawing::Point(12, 12);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(465, 434);
			this->pictureBox1->TabIndex = 0;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::pictureBox1_MouseClick);
			// 
			// listView1
			// 
			this->listView1->HideSelection = false;
			this->listView1->Location = System::Drawing::Point(580, 138);
			this->listView1->Name = L"listView1";
			this->listView1->Size = System::Drawing::Size(112, 161);
			this->listView1->TabIndex = 28;
			this->listView1->TileSize = System::Drawing::Size(30, 30);
			this->listView1->UseCompatibleStateImageBehavior = false;
			this->listView1->View = System::Windows::Forms::View::List;
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(580, 109);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(112, 23);
			this->button3->TabIndex = 27;
			this->button3->Text = L"Class Colour";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(617, 55);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(75, 23);
			this->button2->TabIndex = 26;
			this->button2->Text = L"Apply";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// classCount_textbox
			// 
			this->classCount_textbox->Location = System::Drawing::Point(580, 57);
			this->classCount_textbox->Name = L"classCount_textbox";
			this->classCount_textbox->Size = System::Drawing::Size(31, 20);
			this->classCount_textbox->TabIndex = 25;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->label2->Location = System::Drawing::Point(492, 60);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(82, 13);
			this->label2->TabIndex = 24;
			this->label2->Text = L"Class Count :";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->label3->Location = System::Drawing::Point(516, 85);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(58, 13);
			this->label3->TabIndex = 23;
			this->label3->Text = L"Classes :";
			// 
			// comboBox1
			// 
			this->comboBox1->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Location = System::Drawing::Point(580, 82);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(112, 21);
			this->comboBox1->TabIndex = 22;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->label4->Location = System::Drawing::Point(499, 12);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(198, 25);
			this->label4->TabIndex = 29;
			this->label4->Text = L"------- DATA -------";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->label5->Location = System::Drawing::Point(823, 12);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(252, 25);
			this->label5->TabIndex = 30;
			this->label5->Text = L"------- NETWORK -------";
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(993, 57);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(75, 23);
			this->button4->TabIndex = 33;
			this->button4->Text = L"Apply";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &MyForm::button4_Click);
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(956, 58);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(31, 20);
			this->textBox3->TabIndex = 32;
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->label6->Location = System::Drawing::Point(823, 60);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(127, 13);
			this->label6->TabIndex = 31;
			this->label6->Text = L"Hidden Layer Count :";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->label7->Location = System::Drawing::Point(898, 85);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(52, 13);
			this->label7->TabIndex = 35;
			this->label7->Text = L"Layers :";
			// 
			// comboBox2
			// 
			this->comboBox2->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->comboBox2->FormattingEnabled = true;
			this->comboBox2->Location = System::Drawing::Point(956, 82);
			this->comboBox2->Name = L"comboBox2";
			this->comboBox2->Size = System::Drawing::Size(112, 21);
			this->comboBox2->TabIndex = 34;
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(956, 107);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(31, 20);
			this->textBox1->TabIndex = 37;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->label1->Location = System::Drawing::Point(857, 110);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(93, 13);
			this->label1->TabIndex = 36;
			this->label1->Text = L"Neuron Count :";
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(993, 107);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 25);
			this->button1->TabIndex = 38;
			this->button1->Text = L"Apply";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// listView2
			// 
			this->listView2->HideSelection = false;
			this->listView2->Location = System::Drawing::Point(956, 138);
			this->listView2->Name = L"listView2";
			this->listView2->Size = System::Drawing::Size(112, 161);
			this->listView2->TabIndex = 39;
			this->listView2->TileSize = System::Drawing::Size(110, 30);
			this->listView2->UseCompatibleStateImageBehavior = false;
			this->listView2->View = System::Windows::Forms::View::List;
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->label8->Location = System::Drawing::Point(825, 318);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(125, 13);
			this->label8->TabIndex = 41;
			this->label8->Text = L"Activation Function :";
			// 
			// comboBox3
			// 
			this->comboBox3->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->comboBox3->FormattingEnabled = true;
			this->comboBox3->Location = System::Drawing::Point(956, 315);
			this->comboBox3->Name = L"comboBox3";
			this->comboBox3->Size = System::Drawing::Size(112, 21);
			this->comboBox3->TabIndex = 40;
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->label9->Location = System::Drawing::Point(857, 345);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(93, 13);
			this->label9->TabIndex = 43;
			this->label9->Text = L"Cost Function :";
			// 
			// comboBox4
			// 
			this->comboBox4->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->comboBox4->FormattingEnabled = true;
			this->comboBox4->Location = System::Drawing::Point(956, 342);
			this->comboBox4->Name = L"comboBox4";
			this->comboBox4->Size = System::Drawing::Size(112, 21);
			this->comboBox4->TabIndex = 42;
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->label10->Location = System::Drawing::Point(883, 372);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(67, 13);
			this->label10->TabIndex = 45;
			this->label10->Text = L"Optimizer :";
			// 
			// comboBox5
			// 
			this->comboBox5->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->comboBox5->FormattingEnabled = true;
			this->comboBox5->Location = System::Drawing::Point(956, 369);
			this->comboBox5->Name = L"comboBox5";
			this->comboBox5->Size = System::Drawing::Size(112, 21);
			this->comboBox5->TabIndex = 44;
			// 
			// button5
			// 
			this->button5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->button5->Location = System::Drawing::Point(580, 305);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(112, 31);
			this->button5->TabIndex = 46;
			this->button5->Text = L"Create Data";
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Click += gcnew System::EventHandler(this, &MyForm::button5_Click);
			// 
			// button6
			// 
			this->button6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->button6->Location = System::Drawing::Point(940, 396);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(128, 43);
			this->button6->TabIndex = 47;
			this->button6->Text = L"Create Network";
			this->button6->UseVisualStyleBackColor = true;
			this->button6->Click += gcnew System::EventHandler(this, &MyForm::button6_Click);
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->label11->Location = System::Drawing::Point(490, 356);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(252, 25);
			this->label11->TabIndex = 55;
			this->label11->Text = L"------- ADD DATA -------";
			// 
			// listView3
			// 
			this->listView3->HideSelection = false;
			this->listView3->Location = System::Drawing::Point(580, 447);
			this->listView3->Name = L"listView3";
			this->listView3->Size = System::Drawing::Size(112, 161);
			this->listView3->TabIndex = 54;
			this->listView3->UseCompatibleStateImageBehavior = false;
			this->listView3->View = System::Windows::Forms::View::List;
			// 
			// label13
			// 
			this->label13->AutoSize = true;
			this->label13->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->label13->Location = System::Drawing::Point(516, 405);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(58, 13);
			this->label13->TabIndex = 49;
			this->label13->Text = L"Classes :";
			// 
			// comboBox6
			// 
			this->comboBox6->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->comboBox6->FormattingEnabled = true;
			this->comboBox6->Location = System::Drawing::Point(580, 400);
			this->comboBox6->Name = L"comboBox6";
			this->comboBox6->Size = System::Drawing::Size(112, 21);
			this->comboBox6->TabIndex = 48;
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->label12->Location = System::Drawing::Point(568, 37);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(60, 16);
			this->label12->TabIndex = 56;
			this->label12->Text = L"- Step 1 -";
			// 
			// label14
			// 
			this->label14->AutoSize = true;
			this->label14->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->label14->Location = System::Drawing::Point(922, 42);
			this->label14->Name = L"label14";
			this->label14->Size = System::Drawing::Size(60, 16);
			this->label14->TabIndex = 57;
			this->label14->Text = L"- Step 2 -";
			// 
			// label15
			// 
			this->label15->AutoSize = true;
			this->label15->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->label15->Location = System::Drawing::Point(587, 381);
			this->label15->Name = L"label15";
			this->label15->Size = System::Drawing::Size(60, 16);
			this->label15->TabIndex = 58;
			this->label15->Text = L"- Step 3 -";
			// 
			// label16
			// 
			this->label16->AutoSize = true;
			this->label16->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->label16->Location = System::Drawing::Point(559, 424);
			this->label16->Name = L"label16";
			this->label16->Size = System::Drawing::Size(145, 15);
			this->label16->TabIndex = 59;
			this->label16->Text = L"(Click on the Data Space)";
			// 
			// label17
			// 
			this->label17->AutoSize = true;
			this->label17->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->label17->Location = System::Drawing::Point(101, 449);
			this->label17->Name = L"label17";
			this->label17->Size = System::Drawing::Size(281, 25);
			this->label17->TabIndex = 60;
			this->label17->Text = L"------- DATA SPACE -------";
			// 
			// label18
			// 
			this->label18->AutoSize = true;
			this->label18->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->label18->Location = System::Drawing::Point(793, 449);
			this->label18->Name = L"label18";
			this->label18->Size = System::Drawing::Size(275, 25);
			this->label18->TabIndex = 61;
			this->label18->Text = L"----- RUN NETWORK -----";
			// 
			// label19
			// 
			this->label19->AutoSize = true;
			this->label19->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->label19->Location = System::Drawing::Point(890, 474);
			this->label19->Name = L"label19";
			this->label19->Size = System::Drawing::Size(60, 16);
			this->label19->TabIndex = 62;
			this->label19->Text = L"- Step 4 -";
			// 
			// textBox4
			// 
			this->textBox4->Location = System::Drawing::Point(981, 493);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(31, 20);
			this->textBox4->TabIndex = 64;
			this->textBox4->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::textBox4_KeyDown);
			// 
			// label20
			// 
			this->label20->AutoSize = true;
			this->label20->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->label20->Location = System::Drawing::Point(856, 496);
			this->label20->Name = L"label20";
			this->label20->Size = System::Drawing::Size(119, 13);
			this->label20->TabIndex = 63;
			this->label20->Text = L"Number of Epochs :";
			// 
			// label21
			// 
			this->label21->AutoSize = true;
			this->label21->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->label21->Location = System::Drawing::Point(915, 514);
			this->label21->Name = L"label21";
			this->label21->Size = System::Drawing::Size(20, 16);
			this->label21->TabIndex = 65;
			this->label21->Text = L"or";
			// 
			// label22
			// 
			this->label22->AutoSize = true;
			this->label22->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->label22->Location = System::Drawing::Point(867, 539);
			this->label22->Name = L"label22";
			this->label22->Size = System::Drawing::Size(108, 13);
			this->label22->TabIndex = 66;
			this->label22->Text = L"Error less than € :";
			// 
			// textBox5
			// 
			this->textBox5->Location = System::Drawing::Point(981, 536);
			this->textBox5->Name = L"textBox5";
			this->textBox5->Size = System::Drawing::Size(31, 20);
			this->textBox5->TabIndex = 67;
			this->textBox5->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::textBox5_KeyDown);
			// 
			// button7
			// 
			this->button7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->button7->Location = System::Drawing::Point(940, 562);
			this->button7->Name = L"button7";
			this->button7->Size = System::Drawing::Size(128, 33);
			this->button7->TabIndex = 68;
			this->button7->Text = L"RUN";
			this->button7->UseVisualStyleBackColor = true;
			this->button7->Click += gcnew System::EventHandler(this, &MyForm::button7_Click);
			// 
			// label23
			// 
			this->label23->AutoSize = true;
			this->label23->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->label23->Location = System::Drawing::Point(811, 617);
			this->label23->Name = L"label23";
			this->label23->Size = System::Drawing::Size(68, 13);
			this->label23->TabIndex = 69;
			this->label23->Text = L"Result ==>";
			// 
			// label24
			// 
			this->label24->AutoSize = true;
			this->label24->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->label24->Location = System::Drawing::Point(898, 608);
			this->label24->Name = L"label24";
			this->label24->Size = System::Drawing::Size(57, 13);
			this->label24->TabIndex = 70;
			this->label24->Text = L"Epochs :";
			// 
			// label25
			// 
			this->label25->AutoSize = true;
			this->label25->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->label25->Location = System::Drawing::Point(954, 608);
			this->label25->Name = L"label25";
			this->label25->Size = System::Drawing::Size(14, 13);
			this->label25->TabIndex = 71;
			this->label25->Text = L"0";
			// 
			// label26
			// 
			this->label26->AutoSize = true;
			this->label26->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->label26->Location = System::Drawing::Point(954, 624);
			this->label26->Name = L"label26";
			this->label26->Size = System::Drawing::Size(14, 13);
			this->label26->TabIndex = 73;
			this->label26->Text = L"0";
			// 
			// label27
			// 
			this->label27->AutoSize = true;
			this->label27->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->label27->Location = System::Drawing::Point(913, 624);
			this->label27->Name = L"label27";
			this->label27->Size = System::Drawing::Size(42, 13);
			this->label27->TabIndex = 72;
			this->label27->Text = L"Error :";
			// 
			// button8
			// 
			this->button8->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->button8->Location = System::Drawing::Point(798, 396);
			this->button8->Name = L"button8";
			this->button8->Size = System::Drawing::Size(137, 43);
			this->button8->TabIndex = 74;
			this->button8->Text = L"Delete  Network";
			this->button8->UseVisualStyleBackColor = true;
			this->button8->Click += gcnew System::EventHandler(this, &MyForm::button8_Click);
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(847, 369);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(31, 20);
			this->textBox2->TabIndex = 76;
			// 
			// label28
			// 
			this->label28->AutoSize = true;
			this->label28->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->label28->Location = System::Drawing::Point(748, 372);
			this->label28->Name = L"label28";
			this->label28->Size = System::Drawing::Size(99, 13);
			this->label28->TabIndex = 75;
			this->label28->Text = L"Learning Rate  :";
			// 
			// button9
			// 
			this->button9->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->button9->Location = System::Drawing::Point(798, 562);
			this->button9->Name = L"button9";
			this->button9->Size = System::Drawing::Size(128, 33);
			this->button9->TabIndex = 78;
			this->button9->Text = L"STOP";
			this->button9->UseVisualStyleBackColor = true;
			this->button9->Click += gcnew System::EventHandler(this, &MyForm::button9_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1086, 650);
			this->Controls->Add(this->button9);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->label28);
			this->Controls->Add(this->button8);
			this->Controls->Add(this->label26);
			this->Controls->Add(this->label27);
			this->Controls->Add(this->label25);
			this->Controls->Add(this->label24);
			this->Controls->Add(this->label23);
			this->Controls->Add(this->button7);
			this->Controls->Add(this->textBox5);
			this->Controls->Add(this->label22);
			this->Controls->Add(this->label21);
			this->Controls->Add(this->textBox4);
			this->Controls->Add(this->label20);
			this->Controls->Add(this->label19);
			this->Controls->Add(this->label18);
			this->Controls->Add(this->label17);
			this->Controls->Add(this->label16);
			this->Controls->Add(this->label15);
			this->Controls->Add(this->label14);
			this->Controls->Add(this->label12);
			this->Controls->Add(this->label11);
			this->Controls->Add(this->listView3);
			this->Controls->Add(this->label13);
			this->Controls->Add(this->comboBox6);
			this->Controls->Add(this->button6);
			this->Controls->Add(this->button5);
			this->Controls->Add(this->label10);
			this->Controls->Add(this->comboBox5);
			this->Controls->Add(this->label9);
			this->Controls->Add(this->comboBox4);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->comboBox3);
			this->Controls->Add(this->listView2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->comboBox2);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->listView1);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->classCount_textbox);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->comboBox1);
			this->Controls->Add(this->pictureBox1);
			this->Name = L"MyForm";
			this->Text = L"Artificial Neurol Networks";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: ActivationFunctions^ actFunc;
	private: CostFunctions^ costFunc;
	private: Optimizer^ opt;
	private: ref struct MyColor
	{
		int R;
		int G;
		int B;
		MyColor()
		{
			this->R = 0;
			this->G = 0;
			this->B = 0;
		}
		MyColor(int r, int g, int b)
		{
			this->R = r;
			this->G = g;
			this->B = b;
		}
		void operator()(Color mc)
		{
			this->R = mc.R;
			this->G = mc.G;
			this->B = mc.B;
		}
		bool operator==(Color mc)
		{
			bool check_R = this->R == (int)mc.R;
			bool check_G = this->G == (int)mc.G;
			bool check_B = this->B == (int)mc.B;
			return (check_R && check_G && check_B);
		}
		bool operator==(MyColor^ mc)
		{
			bool check_R = this->R == mc->R;
			bool check_G = this->G == mc->G;
			bool check_B = this->B == mc->B;
			return (check_R && check_G && check_B);
		}
		Color get_color_type ()
		{
			return Color::FromArgb(this->R, this->G, this->B);
		}
		Color get_light_color_type()
		{
			return Color::FromArgb(63, this->R, this->G, this->B);
		}
	};
	private: int class_count;
	private: System::Collections::Generic::List<System::String^> class_names;
	private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
		this->class_names.Clear();
		this->class_colors.Clear();
		this->comboBox1->Items->Clear();
		this->comboBox1->Text = "";
		this->comboBox6->Items->Clear();
		this->comboBox6->Text = "";
		this->listView1->Clear();
		this->listView3->Clear();
		if (System::Text::RegularExpressions::Regex::IsMatch(this->classCount_textbox->Text,
			"^[0-9]*$"))
		{
			this->class_count = System::Convert::ToInt32(this->classCount_textbox->Text);
		}
		else
		{
			MessageBox::Show("Enter a number");
			return;
		}
		for (int i = 0; i < class_count; i++)
		{
			System::String^ class_name = gcnew System::String("class " + System::Convert::ToString(i + 1));
			this->class_names.Add(class_name);
			MyColor^ temp_color = gcnew MyColor();
			this->class_colors.Add(temp_color);
			this->comboBox1->Items->Add(class_name);
			this->comboBox6->Items->Add(class_name);
			ListViewItem^ nLVI1 = gcnew ListViewItem();
			nLVI1->Text = class_name;
			this->listView1->Items->Add(nLVI1);

			ListViewItem^ nLVI = gcnew ListViewItem();
			this->class_data_counts.Add(0);
			System::String^ class_nameX = gcnew System::String(class_name + " : " + System::Convert::ToString(this->class_data_counts[i]));
			nLVI->Text = class_nameX;
			this->listView3->Items->Add(nLVI);
		}
	}
	private: System::Collections::Generic::List<MyColor^> class_colors;
	private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {
		listView3->Clear();
		if (comboBox1->Text == "")
		{
			MessageBox::Show("Pick a Class");
			return;
		}
		this->colorDialog1->ShowDialog();
		Color c = this->colorDialog1->Color;
		this->class_colors[this->class_names.IndexOf(this->comboBox1->Text)](c);
		this->listView1->Clear();
		for (int i = 0; i < this->class_count; i++)
		{
			ListViewItem^ nLVI = gcnew ListViewItem();
			nLVI->Text = this->class_names[i];
			nLVI->ForeColor = Color::FromArgb(this->class_colors[i]->R, this->class_colors[i]->G, this->class_colors[i]->B);
			this->listView1->Items->Add(nLVI);
			ListViewItem^ nLVI1 = gcnew ListViewItem();
			System::String^ class_nameX = gcnew System::String(this->class_names[i] + " : " + System::Convert::ToString(this->class_data_counts[i]));
			nLVI1->Text = class_nameX;
			nLVI1->ForeColor = Color::FromArgb(this->class_colors[i]->R, this->class_colors[i]->G, this->class_colors[i]->B);
			this->listView3->Items->Add(nLVI1);
		}
	}
	private: bool step1;
	private: System::Void button5_Click(System::Object^  sender, System::EventArgs^  e) {
		for (int i = 0; i < this->class_count; i++)
		{
			for (int j = i + 1; j < this->class_count; j++)
			{
				if (class_colors[i] == class_colors[j])
				{
					MessageBox::Show("Class " + System::Convert::ToString(i + 1) + " and" + " Class " + 
						System::Convert::ToString(j + 1) + " are same color. Pick different colours");
					return;
				}
			}
		}
		this->button2->Enabled = false;
		this->button3->Enabled = false;
		this->button5->Enabled = false;
		System::String^ input_layer = gcnew System::String("Input Layer : 10");
		ListViewItem^ nLVIi = gcnew ListViewItem();
		nLVIi->Text = input_layer;
		this->listView2->Items->Add(nLVIi);
		System::String^ output_layer = gcnew System::String("Output Layer : " + System::Convert::ToString(this->class_count));
		ListViewItem^ nLVI = gcnew ListViewItem();
		nLVI->Text = output_layer;
		this->listView2->Items->Add(nLVI);
		step1 = true;
	}
	private: int layer_count;
	private: System::Collections::Generic::List<int> layer_neuron_counts;
	private: System::Collections::Generic::List<System::String^> layer_names;
	private: System::Void button4_Click(System::Object^  sender, System::EventArgs^  e) {
		this->comboBox2->Items->Clear();
		this->layer_names.Clear();
		this->layer_neuron_counts.Clear();
		if (System::Text::RegularExpressions::Regex::IsMatch(this->textBox3->Text,
			"^[0-9]+$"))
		{
			this->layer_count = System::Convert::ToInt32(this->textBox3->Text);
		}
		else
		{
			MessageBox::Show("Enter a number");
			return;
		}

		for (int i = 0; i < this->layer_count; i++)
		{
			System::String^ layer_name = gcnew System::String("Hidden Layer " + System::Convert::ToString(i + 1));
			this->comboBox2->Items->Add(layer_name);
			this->layer_names.Add(layer_name);
			this->layer_neuron_counts.Add(0);
		}
	}
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
		if (comboBox2->Text == "")
		{
			MessageBox::Show("Pick a Layer");
			return;
		}
		if (System::Text::RegularExpressions::Regex::IsMatch(this->textBox1->Text,
			"^[0-9]*$"))
		{
			layer_neuron_counts[this->layer_names.IndexOf(this->comboBox2->Text)] = System::Convert::ToInt32(this->textBox1->Text);
		}
		else
		{
			MessageBox::Show("Enter a number");
			return;
		}
		this->listView2->Clear();
		System::String^ input_layer = gcnew System::String("Input Layer : 10");
		ListViewItem^ nLVIi = gcnew ListViewItem();
		nLVIi->Text = input_layer;
		this->listView2->Items->Add(nLVIi);
		for (int i = 0; i < this->layer_count; i++)
		{
			ListViewItem^ nLVI = gcnew ListViewItem();
			nLVI->Text = this->layer_names[i] + " : " + Convert::ToString(this->layer_neuron_counts[i]);
			this->listView2->Items->Add(nLVI);
		}
		System::String^ output_layer = gcnew System::String("Output Layer : " + System::Convert::ToString(this->class_count));
		ListViewItem^ nLVI = gcnew ListViewItem();
		nLVI->Text = output_layer;
		this->listView2->Items->Add(nLVI);
	}
	private: Network^ network;
	private: bool step2;
	private: System::Void button6_Click(System::Object^  sender, System::EventArgs^  e) {
		if (!step1)
		{
			MessageBox::Show("Complete Step 1");
			return;
		}
		if (comboBox4->Text == "")
		{
			MessageBox::Show("Pick Cost Function");
			return;
		}
		else if (comboBox3->Text == "")
		{
			MessageBox::Show("Pick Activation Function");
			return;
		}
		else if (comboBox3->Text == "")
		{
			MessageBox::Show("Pick Optimizer");
			return;
		}
		if (System::Text::RegularExpressions::Regex::IsMatch(this->textBox2->Text,
			"^[0-9]*[,][0-9]*$"))
		{
			this->opt->set_learning_rate(Convert::ToDouble(textBox2->Text));
		}
		else
		{
			MessageBox::Show("Enter a Valid Learning Rate -> a,b");
			return;
		}
		if (comboBox5->Text == "Batch Gradient Descent")
			this->opt->set_optimizer(BATCH_GRADIENT_DESCENT);
		else if (comboBox5->Text == "Stochastic Gradient Descent")
			this->opt->set_optimizer(STOCHASTIC_GRADIENT_DESCENT);
		else if (comboBox5->Text == "Momentum")
			this->opt->set_optimizer(MOMENTUM);
		else if (comboBox5->Text == "RMSProp")
			this->opt->set_optimizer(RMS_PROP);
		else if (comboBox5->Text == "Adam")
			this->opt->set_optimizer(ADAM);
		else
		{
			MessageBox::Show("Unexpected Error ==> button6_click(), Optimizer");
			return;
		}
		this->costFunc->set_inp_size(this->class_count);
		if (comboBox4->Text == "Mean Squared Error")
			this->costFunc->set_function(MEAN_SQUARED_ERROR);
		else
		{
			MessageBox::Show("Unexpected Error ==> button6_click(), Cost Function");
			return;
		}
		if (comboBox3->Text == "Sigmoid")
			this->actFunc->set_activation_function(SIGMOID);
		else
		{
			MessageBox::Show("Unexpected Error ==> button6_click(), Activation Function");
			return;
		}
		this->network = gcnew Network(actFunc, costFunc, opt, this->class_count);
		Layer^ inpLayer = gcnew Layer(10); // Input Layer 
		network->addLayer(inpLayer);
		for (int i = 0; i < this->layer_count; i++)
		{
			Layer^ nLayer = gcnew Layer(this->layer_neuron_counts[i]);
			network->addLayer(nLayer);
		}
		Layer^ nLayer = gcnew Layer(this->class_count); // Output layer
		network->addLayer(nLayer);
		this->network->init();
		this->textBox1->Enabled = false;
		this->textBox3->Enabled = false;
		this->button4->Enabled = false;
		this->button1->Enabled = false;
		this->button6->Enabled = false;
		this->step2 = true;
	}
	private: System::Collections::Generic::List<System::Collections::Generic::List<int>^> data;
	private: System::Collections::Generic::List<System::Collections::Generic::List<int>^> tick;
	private: System::Collections::Generic::List<int> class_data_counts;
	private: int data_count;
	private: bool step3;
	private: System::Void pictureBox1_MouseClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
		if (!step1)
		{
			MessageBox::Show("Complete Step 1 First");
			return;
		}
		if (this->comboBox6->Text == "")
		{
			MessageBox::Show("Pick a Class");
			return;
		}
		listView3->Clear();
		System::Drawing::Bitmap^ img = (Bitmap^)this->pictureBox1->Image->Clone();
		int pointX = e->X;
		int pointY = e->Y;
		if (pointX == 0) pointX++;
		else if (pointX == this->pictureBox1->Width - 1) pointX--;
		if (pointY == 0) pointX++;
		else if (pointY == this->pictureBox1->Height - 1) pointX--;
		Color c = class_colors[this->class_names.IndexOf(this->comboBox6->Text)]->get_color_type();
		img->SetPixel(pointX, pointY, c);
		img->SetPixel(pointX - 1, pointY, c);
		img->SetPixel(pointX + 1, pointY, c);
		img->SetPixel(pointX, pointY - 1, c);
		img->SetPixel(pointX, pointY + 1, c);

		this->data_count++;
		this->pictureBox1->Image = img;
		/* Create Data */
		System::Collections::Generic::List<int>^ nData = gcnew System::Collections::Generic::List<int>();
		/* Create + as a data */
		/* Point 1 */
		nData->Add(pointX);
		nData->Add(pointY);
		/* Point 2 */
		nData->Add(pointX - 1);
		nData->Add(pointY);
		/* Point 3 */
		nData->Add(pointX + 1);
		nData->Add(pointY);
		/* Point 4 */
		nData->Add(pointX);
		nData->Add(pointY - 1);
		/* Point 5 */
		nData->Add(pointX);
		nData->Add(pointY + 1);

		System::Collections::Generic::List<int>^ nTick = gcnew System::Collections::Generic::List<int>();
		/* Create Tick for Data */
		for (int i = 0; i < this->class_count; i++)
		{
			nTick->Add(0);
		}
		nTick[this->class_names.IndexOf(this->comboBox6->Text)] = 1;

		this->data.Add(nData);
		this->tick.Add(nTick);
		this->class_data_counts[this->class_names.IndexOf(this->comboBox6->Text)]++;
		for (int i = 0; i < class_count; i++)
		{
			ListViewItem^ nLVI = gcnew ListViewItem();
			System::String^ class_nameX = gcnew System::String(this->class_names[i] + " : " + System::Convert::ToString(this->class_data_counts[i]));
			nLVI->Text = class_nameX;
			nLVI->ForeColor = class_colors[i]->get_color_type();
			this->listView3->Items->Add(nLVI);
		}
		this->step3 = true;
	}
	private: System::Void textBox4_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {
		this->textBox5->Text = "";
	}
	private: System::Void textBox5_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {
		this->textBox4->Text = "";
	}
	private: void run()
	{
		bool eps_method = false;
		if (this->textBox4->Text == "")
		{
			eps_method = true;
		}
		std::vector<double*> vec_data;
		std::vector<int*> vec_tick;
		this->costFunc->set_data_count(this->data_count);
		for (int i = 0; i < this->data_count; i++)
		{
			double* nData = new double[10];
			System::Collections::Generic::List<int>^ nd = this->data[i];
			for (int m = 0; m < 10; m++)
			{
				nData[m] = nd[m];
			}
			vec_data.push_back(nData);
			int* nTick = new int[this->class_count];
			System::Collections::Generic::List<int>^ nt = this->tick[i];
			for (int j = 0; j < this->class_count; j++)
			{
				nTick[j] = nt[j];
			}
			vec_tick.push_back(nTick);
		}
		this->normalize(vec_data);
		if (eps_method)
		{
			double epsilon_val;
			if (System::Text::RegularExpressions::Regex::IsMatch(this->textBox5->Text,
				"^[0-9]*[,][0-9]*$"))
			{
				epsilon_val = Convert::ToDouble(this->textBox5->Text);
			}
			else
			{
				MessageBox::Show("Enter a Valid Epsilon Value -> a,b");
				return;
			}

			int epoc = 0;
			while (true)
			{
				double err = this->network->train(vec_data, vec_tick);
				epoc++;
				this->label26->Text = Convert::ToString(err);
				this->label26->Refresh();
				this->label25->Text = Convert::ToString(epoc);
				this->label25->Refresh();
				if (err < epsilon_val) break;
				if (stop_run) break;
			}
		}
		else
		{
			double epsilon_val = 0;
			int epoc_lim;
			if (System::Text::RegularExpressions::Regex::IsMatch(this->textBox4->Text,
				"^[0-9]*$"))
			{
				epoc_lim = Convert::ToInt32(this->textBox4->Text);
			}
			else
			{
				MessageBox::Show("Enter a Valid Epoch Value");
				return;
			}
			int epoc = 0;
			while (epoc < epoc_lim)
			{
				double err = this->network->train(vec_data, vec_tick);
				epoc++;
				this->label26->Text = Convert::ToString(err);
				this->label26->Refresh();
				this->label25->Text = Convert::ToString(epoc);
				this->label25->Refresh();
				if (stop_run) break;
			}
		}
		this->paint_picturebox();
		for (int i = 0; i < (int)vec_data.size(); i++)
		{
			delete vec_data[i];
			delete vec_tick[i];
		}
		vec_data.clear();
		vec_tick.clear();
		button7->Enabled = true;
		button8->Enabled = true;
	}
	private: System::Void button7_Click(System::Object^  sender, System::EventArgs^  e) {
		stop_run = false;
		button7->Enabled = false;
		button8->Enabled = false;
		if (!step2)
		{
			MessageBox::Show("Complete Step 2");
			return;
		}
		if (!step3)
		{
			MessageBox::Show("Complete Step 3");
			return;
		}
		if (this -> textBox4->Text == "" && this->textBox5->Text == "")
		{
			MessageBox::Show("Pick a Method Epoch Count or Epsilon Value");
			return;
		}
		System::Threading::ThreadStart^ ts = gcnew System::Threading::ThreadStart(this, &MyForm::run);
		System::Threading::Thread^ t1 = gcnew System::Threading::Thread(ts);
		t1->Start();
	}
	private: double* means;
	private: double* std_deviations;
	private: void normalize(std::vector<double*> data)
	{
		double sums[10] = { 0 };
		for (int i = 0; i < (int)data.size(); i++)
		{
			for (int j = 0; j < 10; j++)
			{
				sums[j] += data[i][j];
			}
		}

		for (int i = 0; i < 10; i++)
		{
			this->means[i] = sums[i] / (float)data.size();
		}
		double pow_sums[10] = { 0 };
		for (int i = 0; i < (int)data.size(); i++)
		{
			for (int j = 0; j < 10; j++)
			{
				pow_sums[j] += pow((double)data[i][j] - this->means[j], 2.0);
			}
		}

		for (int i = 0; i < 10; i++)
		{
			this->std_deviations[i] = sqrt(pow_sums[i] / (float)data.size());
		}

		for (int i = 0; i < (int)data.size(); i++)
		{
			for (int j = 0; j < 10; j++)
			{
				data[i][j] = ((double)data[i][j] - this->means[j]) / this->std_deviations[j];
			}
		}
	}

	private: void paint_picturebox()
	{
		System::Drawing::Bitmap^ img = (Bitmap^)this->pictureBox1->Image->Clone();
		for (int i = 1; i < this->pictureBox1->Width - 1; i+=2)
		{
			for (int j = 1; j < this->pictureBox1->Height - 1; j+=2)
			{
				double* inp = new double[10];
				inp[0] = i;
				inp[1] = j;
				inp[2] = i - 1;
				inp[3] = j;
				inp[4] = i + 1;
				inp[5] = j;
				inp[6] = i;
				inp[7] = j - 1;
				inp[8] = i;
				inp[9] = j + 1;

				for (int k = 0; k < 10; k++)
				{
					inp[k] = (inp[k] - this->means[k]) / this->std_deviations[k];
				}

				Color c = this->class_colors[this->network->feed_forward(inp)]->get_light_color_type();
				img->SetPixel(i, j, c);
				img->SetPixel(i - 1, j, c);
				img->SetPixel(i + 1, j, c);
				img->SetPixel(i, j - 1, c);
				img->SetPixel(i, j + 1, c);
			}
		}

		/* Add datas back to the picturebox */
		for (int i = 0; i < this->data_count; i++)
		{
			System::Collections::Generic::List<int>^ tc = this->tick[i];
			Color c;
			for (int j = 0; j < this->class_count; j++)
			{
				if (tc[j] == 1) c = this->class_colors[j]->get_color_type();
			}
			System::Collections::Generic::List<int>^ nd = this->data[i];
			img->SetPixel(nd[0], nd[1], c);
			img->SetPixel(nd[2], nd[3], c);
			img->SetPixel(nd[4], nd[5], c);
			img->SetPixel(nd[6], nd[7], c);
			img->SetPixel(nd[8], nd[9], c);
		}
		this->pictureBox1->Image = img;
	}
	private: System::Void button8_Click(System::Object^  sender, System::EventArgs^  e) {
		delete this->network;
		this->textBox1->Enabled = true;
		this->textBox3->Enabled = true;
		this->button4->Enabled = true;
		this->button1->Enabled = true;
		this->button6->Enabled = true;
		this->step2 = false;
	}
	private: bool stop_run;
	private: System::Void button9_Click(System::Object^  sender, System::EventArgs^  e) {
		stop_run = true;
	}
};
}
