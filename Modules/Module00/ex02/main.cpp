#include <QCoreApplication>
#include <QString>
#include <QTextStream>

QString processString(const QString& command, const QString& input) {
    if (command == "up") {
        return input.toUpper();
    } else if (command == "down") {
        return input.toLower();
    } else {
        return "Error: Invalid command. Use 'up' or 'down'.";
    }
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QTextStream out(stdout);

    if (argc < 3) {
        out << "Usage: " << argv[0] << " {command} {string}" << Qt::endl;
        out << "Commands: up, down" << Qt::endl;
        return 1;
    }

    QString command = argv[1];

    // Объединяем все оставшиеся аргументы в одну строку, сохраняя пробелы
    QString input;
    for (int i = 2; i < argc; ++i) {
        if (i > 2) input += ' ';
        input += QString(argv[i]);
    }

    QString result = processString(command, input);
    out << result << Qt::endl;

    return 0;
}
