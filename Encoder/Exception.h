#pragma once

#include <string>
#include <exception>

class User_exception : public std::exception {};

class opening_file_exception : public User_exception {
    const char* what() const noexcept override;
};

class not_selected_strategy : public User_exception {
    const char* what() const noexcept override;
};