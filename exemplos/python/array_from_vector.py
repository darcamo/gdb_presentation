import numpy as np
import gdb
from matplotlib import pyplot as plt


def _cast_to_complex(gdb_value):
    """
    Cast a gdb.Value containing a std::complex<double> number into a python
    complex number.

    Parameters
    ----------
    gdb_value : gdb.Value
        The gdb.Value object containing the complex number

    Returns
    -------
    complex
        The python complex number
    """
    double_t = gdb.lookup_type('double')
    # We need to cast gdb_value into an array of two doubles. Then we can
    # access the real and imaginary parts as the first and second elements
    real_and_imag_parts = gdb_value.cast(double_t.array(1))
    return complex(real_and_imag_parts[0], real_and_imag_parts[1])


def get_list_from(v):
    """
    Get a list containing all elements in a std::vector
    """
    start_mem = v["_M_impl"]["_M_start"]
    finish_mem = v["_M_impl"]["_M_finish"]
    n_elem = finish_mem - start_mem

    return [_cast_to_complex(start_mem[i]) for i in range(n_elem)]


def get_array_from(v):
    return np.array(get_list_from(v))



def plot_vector(v):
    a = get_array_from(v)
    plt.plot(a.real, a.imag, "*")
    plt.show()
