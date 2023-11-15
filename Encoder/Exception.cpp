#include "Exception.h"

const char* opening_file_exception::what() const noexcept
{
    return "File no open";
}

const char* not_selected_strategy::what() const noexcept
{
    return "No strategy selected";
};