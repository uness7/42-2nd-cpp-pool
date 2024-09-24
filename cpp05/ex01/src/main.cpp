# include "../inc/Bureaucrat.hpp"
# include "../inc/Form.hpp"

int     main()
{
    try {
        Bureaucrat  obj("waizi", -11);
        Form    form("A4", 1, 9);

        std::cout << obj << std::endl;
        std::cout << form << std::endl;

        form.beSigned(obj);
        obj.signForm(form);
    } catch(Bureaucrat::GradeTooLowException &e) {
        std::cout << e.what() << std::endl;
    } catch(Bureaucrat::GradeTooHighException &e) {
        std::cout << e.what() << std::endl;
    } catch(Form::GradeTooLowException &e) {
        std::cout << e.what() << std::endl;
    } catch(Form::GradeTooHighException &e) {
        std::cout << e.what() << std::endl;
    }
    return (0);
}
