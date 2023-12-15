#include "../array-lib/array.h"


// abstract class for all network modules (fc, relu, etc.)
class Module {
    public:
        Module() = default;
        virtual ~Module() = default;
    private:
        virtual Array2D forward(const Array2D& input) = 0;
        virtual Array2D backward(const Array2D& grad) = 0;
};
