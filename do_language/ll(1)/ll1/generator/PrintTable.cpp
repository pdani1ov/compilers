#include "PrintTable.h"

void PrintDirectionSymbols(const TableRow& tableStr, std::ostream& outputFile)
{
    int index = 0;
    //outputFile << "\"";
    for (const std::string& directionSymbol : tableStr.directionSymbols)
    {
        std::string symbol = directionSymbol == ";" ? ".," : directionSymbol;
        outputFile << directionSymbol;
        if (index != tableStr.directionSymbols.size() - 1)
        {
            outputFile << " | ";
        }
        index++;
    }
    outputFile << "\t";
}

void PrintBoolValue(const bool value, std::ostream& outputFile)
{
    if (value)
    {
        outputFile << "+";
    }
    else
    {
        outputFile << "-";
    }
    outputFile << "\t";
}

void PrintPointer(const std::optional<size_t> pointer, std::ostream& outputFile)
{
    if (pointer.has_value())
    {
        outputFile << pointer.value() + 1;
    }
    else
    {
        outputFile << "NULL";
    }
    outputFile << "\t";
}

void PrintTable(const std::vector<TableRow>& table, std::ostream& outputFile)
{
    outputFile << "index\tsymbol\tdirectionSymbols\tshift\terror\tpointer\tstack\tend" << std::endl;

    for (size_t i = 0; i < table.size(); i++)
    {
        const TableRow& tableStr = table[i];
        std::string symbol = tableStr.symbol == ";" ? "\";\"" : tableStr.symbol;
        outputFile << i + 1 << "\t"
            << symbol << "\t";
        PrintDirectionSymbols(tableStr, outputFile);
        PrintBoolValue(tableStr.shift, outputFile);
        PrintBoolValue(tableStr.error, outputFile);
        PrintPointer(tableStr.pointer, outputFile);
        PrintBoolValue(tableStr.stack, outputFile);
        PrintBoolValue(tableStr.end, outputFile);
        outputFile << std::endl;
    }
}