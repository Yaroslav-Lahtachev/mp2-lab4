#pragma once
#include "windows.h"
#include <stdio.h>
#include <vcclr.h>
#include <fstream>
#include <string>


namespace view_graph {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace Microsoft::Glee::Drawing;
	using namespace System::Runtime::InteropServices;
	using namespace std;


	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
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
	private: Microsoft::Glee::GraphViewerGdi::GViewer^  gViewer1;
	private: System::Windows::Forms::Button^  cancel;
	private: System::Windows::Forms::NumericUpDown^  edgUpDown;
	private: System::Windows::Forms::NumericUpDown^  verUpDown;
	private: System::Windows::Forms::Button^  deleteImg;
	private: System::Windows::Forms::Button^  findFrame;
	private: System::Windows::Forms::Button^  stepBystep;
	private: System::Windows::Forms::Label^  labelKruskl;
	private: System::Windows::Forms::Button^  makeRandom;

	private: System::Windows::Forms::Label^  labelEdg;
	private: System::Windows::Forms::Label^  labelVer;
	private: System::Windows::Forms::NumericUpDown^  minWUpDown;
	private: System::Windows::Forms::NumericUpDown^  maxWUpDown;
	private: System::Windows::Forms::Label^  labelMaxW;
	private: System::Windows::Forms::Label^  labelMinW;
	private: System::Windows::Forms::NumericUpDown^  qnumUpDown;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Button^  queueOk;
	private: System::Windows::Forms::TextBox^  startBox;
	private: System::Windows::Forms::TextBox^  weightBox;
	private: System::Windows::Forms::TextBox^  endBox;
	private: System::Windows::Forms::Button^  addEdge;

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
			this->gViewer1 = (gcnew Microsoft::Glee::GraphViewerGdi::GViewer());
			this->cancel = (gcnew System::Windows::Forms::Button());
			this->edgUpDown = (gcnew System::Windows::Forms::NumericUpDown());
			this->verUpDown = (gcnew System::Windows::Forms::NumericUpDown());
			this->deleteImg = (gcnew System::Windows::Forms::Button());
			this->findFrame = (gcnew System::Windows::Forms::Button());
			this->stepBystep = (gcnew System::Windows::Forms::Button());
			this->labelKruskl = (gcnew System::Windows::Forms::Label());
			this->makeRandom = (gcnew System::Windows::Forms::Button());
			this->labelEdg = (gcnew System::Windows::Forms::Label());
			this->labelVer = (gcnew System::Windows::Forms::Label());
			this->minWUpDown = (gcnew System::Windows::Forms::NumericUpDown());
			this->maxWUpDown = (gcnew System::Windows::Forms::NumericUpDown());
			this->labelMaxW = (gcnew System::Windows::Forms::Label());
			this->labelMinW = (gcnew System::Windows::Forms::Label());
			this->qnumUpDown = (gcnew System::Windows::Forms::NumericUpDown());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->queueOk = (gcnew System::Windows::Forms::Button());
			this->startBox = (gcnew System::Windows::Forms::TextBox());
			this->weightBox = (gcnew System::Windows::Forms::TextBox());
			this->endBox = (gcnew System::Windows::Forms::TextBox());
			this->addEdge = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->edgUpDown))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->verUpDown))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->minWUpDown))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->maxWUpDown))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->qnumUpDown))->BeginInit();
			this->SuspendLayout();
			// 
			// gViewer1
			// 
			this->gViewer1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->gViewer1->AsyncLayout = false;
			this->gViewer1->AutoScroll = true;
			this->gViewer1->BackwardEnabled = false;
			this->gViewer1->ForwardEnabled = false;
			this->gViewer1->Graph = nullptr;
			this->gViewer1->Location = System::Drawing::Point(176, 2);
			this->gViewer1->MouseHitDistance = 0.05;
			this->gViewer1->Name = L"gViewer1";
			this->gViewer1->NavigationVisible = true;
			this->gViewer1->PanButtonPressed = false;
			this->gViewer1->SaveButtonVisible = true;
			this->gViewer1->Size = System::Drawing::Size(759, 861);
			this->gViewer1->TabIndex = 38;
			this->gViewer1->ZoomF = 1;
			this->gViewer1->ZoomFraction = 0.5;
			this->gViewer1->ZoomWindowThreshold = 0.05;
			// 
			// cancel
			// 
			this->cancel->Location = System::Drawing::Point(8, 377);
			this->cancel->Margin = System::Windows::Forms::Padding(2);
			this->cancel->Name = L"cancel";
			this->cancel->Size = System::Drawing::Size(74, 32);
			this->cancel->TabIndex = 61;
			this->cancel->Text = L"cancel";
			this->cancel->UseVisualStyleBackColor = false;
			this->cancel->Click += gcnew System::EventHandler(this, &MyForm::cancel_Click);
			// 
			// edgUpDown
			// 
			this->edgUpDown->Location = System::Drawing::Point(85, 36);
			this->edgUpDown->Margin = System::Windows::Forms::Padding(2);
			this->edgUpDown->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, 0 });
			this->edgUpDown->Name = L"edgUpDown";
			this->edgUpDown->Size = System::Drawing::Size(52, 20);
			this->edgUpDown->TabIndex = 60;
			// 
			// verUpDown
			// 
			this->verUpDown->Location = System::Drawing::Point(85, 12);
			this->verUpDown->Margin = System::Windows::Forms::Padding(2);
			this->verUpDown->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, 0 });
			this->verUpDown->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			this->verUpDown->Name = L"verUpDown";
			this->verUpDown->Size = System::Drawing::Size(52, 20);
			this->verUpDown->TabIndex = 59;
			this->verUpDown->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			// 
			// deleteImg
			// 
			this->deleteImg->Location = System::Drawing::Point(86, 377);
			this->deleteImg->Margin = System::Windows::Forms::Padding(2);
			this->deleteImg->Name = L"deleteImg";
			this->deleteImg->Size = System::Drawing::Size(74, 32);
			this->deleteImg->TabIndex = 58;
			this->deleteImg->Text = L"delete img";
			this->deleteImg->UseVisualStyleBackColor = false;
			this->deleteImg->Click += gcnew System::EventHandler(this, &MyForm::deleteImg_Click_1);
			// 
			// findFrame
			// 
			this->findFrame->Location = System::Drawing::Point(8, 299);
			this->findFrame->Margin = System::Windows::Forms::Padding(2);
			this->findFrame->Name = L"findFrame";
			this->findFrame->Size = System::Drawing::Size(152, 49);
			this->findFrame->TabIndex = 57;
			this->findFrame->Text = L"find spanning tree";
			this->findFrame->UseVisualStyleBackColor = true;
			this->findFrame->Click += gcnew System::EventHandler(this, &MyForm::findFrame_Click_1);
			// 
			// stepBystep
			// 
			this->stepBystep->Location = System::Drawing::Point(8, 246);
			this->stepBystep->Margin = System::Windows::Forms::Padding(2);
			this->stepBystep->Name = L"stepBystep";
			this->stepBystep->Size = System::Drawing::Size(152, 49);
			this->stepBystep->TabIndex = 56;
			this->stepBystep->Text = L"step by step";
			this->stepBystep->UseVisualStyleBackColor = true;
			this->stepBystep->Click += gcnew System::EventHandler(this, &MyForm::stepBystep_Click_1);
			// 
			// labelKruskl
			// 
			this->labelKruskl->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->labelKruskl->Location = System::Drawing::Point(8, 191);
			this->labelKruskl->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->labelKruskl->Name = L"labelKruskl";
			this->labelKruskl->Size = System::Drawing::Size(152, 53);
			this->labelKruskl->TabIndex = 55;
			this->labelKruskl->Text = L"Kruskl";
			this->labelKruskl->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// makeRandom
			// 
			this->makeRandom->Location = System::Drawing::Point(8, 140);
			this->makeRandom->Margin = System::Windows::Forms::Padding(2);
			this->makeRandom->Name = L"makeRandom";
			this->makeRandom->Size = System::Drawing::Size(129, 32);
			this->makeRandom->TabIndex = 42;
			this->makeRandom->Text = L"create random";
			this->makeRandom->UseVisualStyleBackColor = true;
			this->makeRandom->Click += gcnew System::EventHandler(this, &MyForm::makeRandom_Click_1);
			// 
			// labelEdg
			// 
			this->labelEdg->AutoSize = true;
			this->labelEdg->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->labelEdg->Location = System::Drawing::Point(45, 36);
			this->labelEdg->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->labelEdg->Name = L"labelEdg";
			this->labelEdg->Size = System::Drawing::Size(36, 13);
			this->labelEdg->TabIndex = 40;
			this->labelEdg->Text = L"edges";
			// 
			// labelVer
			// 
			this->labelVer->AutoSize = true;
			this->labelVer->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->labelVer->Location = System::Drawing::Point(37, 12);
			this->labelVer->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->labelVer->Name = L"labelVer";
			this->labelVer->Size = System::Drawing::Size(44, 13);
			this->labelVer->TabIndex = 39;
			this->labelVer->Text = L"vertices";
			// 
			// minWUpDown
			// 
			this->minWUpDown->Location = System::Drawing::Point(84, 80);
			this->minWUpDown->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, 0 });
			this->minWUpDown->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, System::Int32::MinValue });
			this->minWUpDown->Name = L"minWUpDown";
			this->minWUpDown->Size = System::Drawing::Size(52, 20);
			this->minWUpDown->TabIndex = 62;
			// 
			// maxWUpDown
			// 
			this->maxWUpDown->Location = System::Drawing::Point(84, 106);
			this->maxWUpDown->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, 0 });
			this->maxWUpDown->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, System::Int32::MinValue });
			this->maxWUpDown->Name = L"maxWUpDown";
			this->maxWUpDown->Size = System::Drawing::Size(52, 20);
			this->maxWUpDown->TabIndex = 63;
			// 
			// labelMaxW
			// 
			this->labelMaxW->AutoSize = true;
			this->labelMaxW->Location = System::Drawing::Point(16, 106);
			this->labelMaxW->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->labelMaxW->Name = L"labelMaxW";
			this->labelMaxW->Size = System::Drawing::Size(63, 13);
			this->labelMaxW->TabIndex = 64;
			this->labelMaxW->Text = L"max Weight";
			// 
			// labelMinW
			// 
			this->labelMinW->AutoSize = true;
			this->labelMinW->Location = System::Drawing::Point(19, 80);
			this->labelMinW->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->labelMinW->Name = L"labelMinW";
			this->labelMinW->Size = System::Drawing::Size(60, 13);
			this->labelMinW->TabIndex = 65;
			this->labelMinW->Text = L"min Weight";
			// 
			// qnumUpDown
			// 
			this->qnumUpDown->Location = System::Drawing::Point(57, 440);
			this->qnumUpDown->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 3, 0, 0, 0 });
			this->qnumUpDown->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			this->qnumUpDown->Name = L"qnumUpDown";
			this->qnumUpDown->Size = System::Drawing::Size(52, 20);
			this->qnumUpDown->TabIndex = 66;
			this->qnumUpDown->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			// 
			// label1
			// 
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(46, 414);
			this->label1->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(77, 23);
			this->label1->TabIndex = 67;
			this->label1->Text = L"queue type";
			this->label1->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// queueOk
			// 
			this->queueOk->Location = System::Drawing::Point(115, 450);
			this->queueOk->Name = L"queueOk";
			this->queueOk->Size = System::Drawing::Size(100, 50);
			this->queueOk->TabIndex = 35;
			this->queueOk->Text = L"Apply";
			this->queueOk->UseVisualStyleBackColor = true;
			this->queueOk->Click += gcnew System::EventHandler(this, &MyForm::queueOk_Click);
			// 
			// startBox
			// 
			this->startBox->Location = System::Drawing::Point(5, 500);
			this->startBox->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->startBox->Name = L"startBox";
			this->startBox->Size = System::Drawing::Size(47, 22);
			this->startBox->TabIndex = 15;
			// 
			// weightBox
			// 
			this->weightBox->Location = System::Drawing::Point(130, 500);
			this->weightBox->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->weightBox->Name = L"weightBox";
			this->weightBox->Size = System::Drawing::Size(47, 22);
			this->weightBox->TabIndex = 16;
			// 
			// endBox
			// 
			this->endBox->Location = System::Drawing::Point(68, 500);
			this->endBox->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->endBox->Name = L"endBox";
			this->endBox->Size = System::Drawing::Size(47, 22);
			this->endBox->TabIndex = 17;
			// 
			// addEdge
			// 
			this->addEdge->Location = System::Drawing::Point(5, 550);
			this->addEdge->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->addEdge->Name = L"addEdge";
			this->addEdge->Size = System::Drawing::Size(172, 39);
			this->addEdge->TabIndex = 18;
			this->addEdge->Text = L"Add";
			this->addEdge->UseVisualStyleBackColor = true;
			this->addEdge->Click += gcnew System::EventHandler(this, &MyForm::AddEdgeClick);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(934, 862);
			//this->Controls->Add(this->queueOk);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->qnumUpDown);
			this->Controls->Add(this->labelMinW);
			this->Controls->Add(this->labelMaxW);
			this->Controls->Add(this->maxWUpDown);
			this->Controls->Add(this->minWUpDown);
			this->Controls->Add(this->cancel);
			this->Controls->Add(this->edgUpDown);
			this->Controls->Add(this->verUpDown);
			this->Controls->Add(this->deleteImg);
			this->Controls->Add(this->findFrame);
			this->Controls->Add(this->stepBystep);
			this->Controls->Add(this->labelKruskl);
			this->Controls->Add(this->makeRandom);
			this->Controls->Add(this->labelEdg);
			this->Controls->Add(this->labelVer);
			this->Controls->Add(this->gViewer1);
			this->Controls->Add(this->addEdge);
			this->Controls->Add(this->endBox);
			this->Controls->Add(this->weightBox);
			this->Controls->Add(this->startBox);
			this->MinimumSize = System::Drawing::Size(900, 550);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->edgUpDown))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->verUpDown))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->minWUpDown))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->maxWUpDown))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->qnumUpDown))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
#pragma endregion
		Graph ^currGraph;
		static unsigned int ver = 0;
		static unsigned int edg = 0;
		static int minW = 0;
		static int maxW = 0;
		static int qnum = 0;


	private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e) {
		currGraph = gcnew Graph("graph");
	}

	private: System::Void loadGraph() {
		ifstream load("tree.txt");
		int tmpE, tmpV, q;
		load >> tmpV;
		load >> tmpE;
		
		ver = tmpV;
		edg = tmpE;
		delete gViewer1->Graph;
		currGraph = gcnew Graph("graph");
		currGraph->GraphAttr->EdgeAttr->ArrowHeadAtTarget = Microsoft::Glee::Drawing::ArrowStyle::None;
		for (int i = 0; i<ver; i++)
			currGraph->AddNode(System::Convert::ToString(i));
		int n, k;
		float w;
		for (int i = 0; i<edg; i++)
		{
			load >> n;
			load >> k;
			load >> w;
			currGraph->AddEdge(System::Convert::ToString(n), System::Convert::ToString(w), System::Convert::ToString(k));
		}
		gViewer1->Graph = currGraph;
		load.close();
	}

	private: int createProcess() {

		STARTUPINFO si;
		PROCESS_INFORMATION pi;
		ZeroMemory(&pi, sizeof(pi));
		ZeroMemory(&si, sizeof(STARTUPINFO));

		System::String^ verS = System::Convert::ToString(ver);
		System::String^ edgS = System::Convert::ToString(edg);
		System::String^ minS = System::Convert::ToString(minW);
		System::String^ maxS = System::Convert::ToString(maxW);
		System::String^ qnums = System::Convert::ToString(qnum);

		System::String^ fullCommandLineS = System::String::Concat("sample-Kruskl.exe ", verS, " ", edgS, " ", minS, " ", maxS, " ", qnums);

		wchar_t *argPtr = (wchar_t *)Marshal::StringToHGlobalUni(fullCommandLineS).ToPointer();

		if (CreateProcess(0, argPtr, 0, 0, TRUE, CREATE_NO_WINDOW, 0, 0, &si, &pi))
			WaitForSingleObject(pi.hProcess, INFINITE);
		else
		{
			CloseHandle(pi.hProcess);
			CloseHandle(pi.hThread);
			return -1;
		}
		DWORD exitCode;
		GetExitCodeProcess(pi.hProcess, &exitCode);
		if (exitCode)
		{
			System::String^ message = "wrong input";
			System::String^ caption = "Error";
			MessageBox::Show(message, caption, MessageBoxButtons::OK, MessageBoxIcon::Question);
			return -2;
		}
		CloseHandle(pi.hProcess);
		CloseHandle(pi.hThread);
		return 0;
	}

	private: System::Void cancel_Click(System::Object^  sender, System::EventArgs^  e) {
		stepBystep->Enabled = true;
		findFrame->Enabled = true;
		loadGraph();
	}

	private: System::Void makeRandom_Click_1(System::Object^  sender, System::EventArgs^  e) {
		stepBystep->Enabled = true;
		findFrame->Enabled = true;
		deleteImg->Enabled = true;
		ver = (unsigned int)verUpDown->Value;
		edg = (unsigned int)edgUpDown->Value;
		minW = (int)minWUpDown->Value;
		maxW = (int)maxWUpDown->Value;
		qnum = (int)qnumUpDown->Value;
		if (createProcess())
			return;
		loadGraph();
	}
	private: System::Void deleteImg_Click_1(System::Object^  sender, System::EventArgs^  e) {
		stepBystep->Enabled = false;
		findFrame->Enabled = true;
		cancel->Enabled = false;
		deleteImg->Enabled = false;
		delete gViewer1->Graph;
		Graph ^currGraph = gcnew Graph("graph");
		gViewer1->Graph = currGraph;
	}

	private: System::Void stepBystep_Click_1(System::Object^  sender, System::EventArgs^  e) {
		Graph ^currGraph = gViewer1->Graph;
		currGraph->GraphAttr->EdgeAttr->ArrowHeadAtTarget = Microsoft::Glee::Drawing::ArrowStyle::None;
		ifstream load("tree.txt");
		int tmpV, tmpE;
		load >> tmpV;
		load >> tmpE;
		ver = tmpV;
		edg = tmpE;
		int n, k;
		float w;
		for (int i = 0; i<edg; i++)
		{
			load >> n;
			load >> k;
			load >> w;
		}
		while (!load.eof())
		{
			load >> n;
			load >> k;
			load >> w;
			for (int i = 0; i<currGraph->Edges->Count; i++)
			{
				Edge^ edge = currGraph->Edges[i];
				if (currGraph->Edges[i]->Source == System::Convert::ToString(n) && currGraph->Edges[i]->Target == System::Convert::ToString(k) || currGraph->Edges[i]->Source == System::Convert::ToString(k) && currGraph->Edges[i]->Target == System::Convert::ToString(n))
					if (currGraph->Edges[i]->Attr->Color != Microsoft::Glee::Drawing::Color::Blue)
					{
						currGraph->Edges[i]->Attr->LineWidth = 4;
						currGraph->Edges[i]->Attr->Color = Microsoft::Glee::Drawing::Color::Blue;
						gViewer1->Graph = currGraph;
						load.close();
						return;
					}
			}
		}
		stepBystep->Enabled = false;
		findFrame->Enabled = false;
		cancel->Enabled = true;
		gViewer1->Graph = currGraph;
		load.close();
	}
	private: System::Void findFrame_Click_1(System::Object^  sender, System::EventArgs^  e) {
		cancel_Click(sender, e);
		Graph ^g = gViewer1->Graph;
		for (int i = 0; i<ver - 1; i++)
			stepBystep_Click_1(sender, e);
		stepBystep->Enabled = false;
		findFrame->Enabled = false;
		cancel->Enabled = true;
	}
	

	private: System::Void queueOk_Click(System::Object^  sender, System::EventArgs^  e) {
		createFile();
		System::String^ sourseGraph = "res0.txt";
		System::String^ pathToExec1 = "sample-Kruskl.exe";
		if (createProcFile(pathToExec1, sourseGraph))
			return;
	}

	private: int createProcFile(System::String^ pathToExec, System::String^ sourseGraph) {

		System::String^ fullCommandLineS = System::String::Concat(pathToExec, " ", sourseGraph);
		wchar_t *argPtr = (wchar_t *)Marshal::StringToHGlobalUni(fullCommandLineS).ToPointer();

		STARTUPINFO si;
		PROCESS_INFORMATION pi;
		ZeroMemory(&pi, sizeof(pi));
		ZeroMemory(&si, sizeof(STARTUPINFO));

		if (CreateProcess(0, argPtr, 0, 0, TRUE, CREATE_NO_WINDOW, 0, 0, &si, &pi))
			WaitForSingleObject(pi.hProcess, INFINITE);
		else {
			CloseHandle(pi.hProcess);
			CloseHandle(pi.hThread);
			return -1;
		}

		DWORD exitCode;
		GetExitCodeProcess(pi.hProcess, &exitCode);
		if (exitCode) {
			System::String^ message = "Error!\nSomething went wrong!";
			System::String^ caption = "Error";
			MessageBox::Show(message, caption, MessageBoxButtons::OK, MessageBoxIcon::Question);
			return -2;
		}
		CloseHandle(pi.hProcess);
		CloseHandle(pi.hThread);
		return 0;
	}
	private: System::Void createFile() {
		using namespace std;
		fstream input;
		input.open("tree.txt", fstream::in | fstream::out);
		if (!input) {
			ofstream ofs("tree.txt");
			ofs.close();
		}
		remove("res0.txt");
		ofstream graph("res0.txt");

		int n = 0, m = 0;
		input >> n;
		input >> m;
		int isConnected;
		input >> isConnected;

		qnum = (int)qnumUpDown->Value;

		graph << n << ' ' << m << ' ' << qnum;

		int N, K;
		float weight;
		for (int j = 0; j < m; j++) {
			graph << endl;
			input >> N;
			input >> K;
			input >> weight;
			graph << N << ' ' << K << ' ' << weight;
		}
		input.close();
		graph.close();
	}
	private: System::Void AddEdgeClick(System::Object^  sender, System::EventArgs^  e) {
		stepBystep->Enabled = true;
		findFrame->Enabled = true;
		using namespace std;
		int newN;
		int newK;
		float newWeight;
		try {
			newN = (int)(Convert::ToInt32(startBox->Text));
			newK = (int)(Convert::ToInt32(endBox->Text));
			newWeight = (float)(Convert::ToDouble(weightBox->Text));
		}
		catch (...) {
			System::String^ message = "Error!\nInvalid parametrs for edge!";
			System::String^ caption = "Error";
			MessageBox::Show(message, caption, MessageBoxButtons::OK, MessageBoxIcon::Question);
			return;
		}

		fstream input;
		input.open("tree.txt", fstream::in | fstream::out);
		if (!input) {
			ofstream ofs("tree.txt");
			ofs.close();
		}

		remove("res0.txt");
		ofstream graph("res0.txt");

		int n = 0, m = 0;
		input >> n;
		input >> m;
		


		if ((newN >= n) || (newK >= n))
			n = max(newN + 1, newK + 1);

		qnum = (int)qnumUpDown->Value;
		graph << n << ' ' << m + 1 << ' ' << qnum << endl;


		ver = n;
		edg = m + 1;

		int N, K;
		float weight;
		for (int j = 0; j < m; j++) {
			input >> N;
			input >> K;
			input >> weight;
			graph << N << ' ' << K << ' ' << weight << endl;
		}

		graph << newN << ' ' << newK << ' ' << newWeight;

		input.close();
		graph.close();

		System::String^ sourseGraph = "res0.txt";
		System::String^ pathToExec1 = "sample-Kruskl.exe";
		if (createProcFile(pathToExec1, sourseGraph))
			return;
	
		loadGraph();
	}
	};
}
