#include <QApplication>
#include <QComboBox>
#include <QLabel>
#include <QMainWindow>
#include <QPushButton>
#include <QStackedWidget>
#include <QTextEdit>
#include <QVBoxLayout>
#include <QWidget>

class LandCategorization : public QMainWindow {
    Q_OBJECT

public:
    LandCategorization(QWidget *parent = nullptr) : QMainWindow(parent) {
        setupUI();
    }

private:
    QWidget *mainPanel, *agriculturalPanel, *commercialPanel;
    QStackedWidget *stackedWidget;
    QTextEdit *resultArea;
    
    void setupUI() {
        this->setWindowTitle("Land Categorization");
        this->resize(600, 400);

        stackedWidget = new QStackedWidget;
        
        // Main Panel
        mainPanel = new QWidget;
        QVBoxLayout *mainLayout = new QVBoxLayout(mainPanel);
        QLabel *titleLabel = new QLabel("Select Area Type:");
        titleLabel->setAlignment(Qt::AlignCenter);
        titleLabel->setStyleSheet("font-weight: bold; font-size: 18px;");
        mainLayout->addWidget(titleLabel);

        QPushButton *agriculturalButton = new QPushButton("Agricultural Area");
        QPushButton *commercialButton = new QPushButton("Commercial and Residential Area");
        mainLayout->addWidget(agriculturalButton);
        mainLayout->addWidget(commercialButton);

        connect(agriculturalButton, &QPushButton::clicked, this, &LandCategorization::showAgriculturalPanel);
        connect(commercialButton, &QPushButton::clicked, this, &LandCategorization::showCommercialPanel);

        stackedWidget->addWidget(mainPanel);
        
        // Agricultural Panel
        agriculturalPanel = new QWidget;
        QVBoxLayout *agriLayout = new QVBoxLayout(agriculturalPanel);
        
        QStringList irrigationOptions = {"Continuous irrigation facility", "Partial irrigation facility", "Depending on the rainfall", "Dry"};
        QStringList roadOptions = {"Main Road", "Gravel Road", "Horse Road", "Trial Road", "Without Road facility"};
        QStringList cropOptions = {"More than one crop to be farmed", "Only one crop to be farmed"};
        QStringList soilOptions = {"Good Fertile", "Mixed (Dumat)", "Marcy Land (Dhap)", "Sandy (Balaute)", "Graveled (Dhungyan)"};
        QStringList altitudeOptions = {"Upto 500 meter", "More than 500 meter upto 1000 meter", "More than 1000 meter upto 2000 meter", "More than 2000 meter upto 3000 meter", "More than 3000 meter"};
        QStringList marketOptions = {"Upto 5 km.", "More than 5 km. upto 10 km.", "More than that"};
        QStringList elevationOptions = {"Plain (Samatal)", "Terrain Terrace (Tari Garha)", "Slope without terrace (Garha)", "Slope (Bhiralo)"};

        QComboBox *irrigationCombo = addComboBox(agriLayout, "Irrigation Facility:", irrigationOptions);
        QComboBox *roadCombo = addComboBox(agriLayout, "Road Facility:", roadOptions);
        QComboBox *cropCombo = addComboBox(agriLayout, "Crop Farming:", cropOptions);
        QComboBox *soilCombo = addComboBox(agriLayout, "Types of Soil:", soilOptions);
        QComboBox *altitudeCombo = addComboBox(agriLayout, "Altitude of Land from sea level:", altitudeOptions);
        QComboBox *marketCombo = addComboBox(agriLayout, "Agriculture Market Facility:", marketOptions);
        QComboBox *elevationCombo = addComboBox(agriLayout, "Elevation of Land:", elevationOptions);

        QPushButton *calculateAgriButton = new QPushButton("Calculate");
        resultArea = new QTextEdit;
        resultArea->setReadOnly(true);

        agriLayout->addWidget(calculateAgriButton);
        agriLayout->addWidget(resultArea);

        connect(calculateAgriButton, &QPushButton::clicked, [this, irrigationCombo, roadCombo, cropCombo, soilCombo, altitudeCombo, marketCombo, elevationCombo]() {
            int totalMarks = getAgricultureMarks(
                irrigationCombo->currentIndex(), roadCombo->currentIndex(), cropCombo->currentIndex(), 
                soilCombo->currentIndex(), altitudeCombo->currentIndex(), marketCombo->currentIndex(), elevationCombo->currentIndex()
            );
            resultArea->setText("Total Marks: " + QString::number(totalMarks) + "\nGrade: " + getAgriculturalGrade(totalMarks));
        });

        stackedWidget->addWidget(agriculturalPanel);
        
        // Add stackedWidget to the main window
        setCentralWidget(stackedWidget);
    }

    QComboBox* addComboBox(QVBoxLayout *layout, const QString &label, const QStringList &options) {
        layout->addWidget(new QLabel(label));
        QComboBox *comboBox = new QComboBox;
        comboBox->addItems(options);
        layout->addWidget(comboBox);
        return comboBox;
    }

    void showAgriculturalPanel() {
        stackedWidget->setCurrentWidget(agriculturalPanel);
    }

    int getAgricultureMarks(int irrigationChoice, int roadChoice, int cropChoice, int soilChoice, int altitudeChoice, int marketChoice, int elevationChoice) {
        int marks = 0;
        marks += irrigationChoice == 0 ? 10 : (irrigationChoice == 1 ? 7 : (irrigationChoice == 2 ? 3 : 1));
        marks += roadChoice == 0 ? 8 : (roadChoice == 1 ? 6 : (roadChoice == 2 ? 4 : (roadChoice == 3 ? 2 : 1)));
        marks += cropChoice == 0 ? 4 : 2;
        marks += soilChoice == 0 ? 10 : (soilChoice == 1 ? 8 : (soilChoice == 2 ? 5 : (soilChoice == 3 ? 3 : 2)));
        marks += altitudeChoice == 0 ? 6 : (altitudeChoice == 1 ? 5 : (altitudeChoice == 2 ? 4 : (altitudeChoice == 3 ? 3 : 1)));
        marks += marketChoice == 0 ? 4 : (marketChoice == 1 ? 2 : 1);
        marks += elevationChoice == 0 ? 8 : (elevationChoice == 1 ? 5 : (elevationChoice == 2 ? 3 : 1));
        return marks;
    }

    QString getAgriculturalGrade(int marks) {
        if (marks >= 46) return "1a Grade";
        else if (marks >= 36) return "1b Grade";
        else if (marks >= 26) return "1c Grade";
        else if (marks >= 16) return "1d Grade";
        else if (marks >= 1) return "1e Grade";
        else return "Ungraded";
    }
};

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    LandCategorization window;
    window.show();
    return app.exec();
}
