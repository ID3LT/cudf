======
Series
======
.. currentmodule:: cudf

Constructor
-----------
.. autosummary::
   :toctree: api/
   :template: autosummary/class_with_autosummary.rst

   Series

Attributes
----------
**Axes**

.. autosummary::
   :toctree: api/

   Series.index
   Series.values
   Series.data
   Series.dtype
   Series.shape
   Series.ndim
   Series.nullable
   Series.nullmask
   Series.null_count
   Series.size
   Series.memory_usage
   Series.has_nulls
   Series.empty
   Series.name
   Series.valid_count
   Series.values_host

Conversion
----------
.. autosummary::
   :toctree: api/

   Series.astype
   Series.copy
   Series.to_list
   Series.__array__
   Series.as_mask
   Series.scale


Indexing, iteration
-------------------
.. autosummary::
   :toctree: api/

   Series.loc
   Series.iloc
   Series.__iter__
   Series.items
   Series.iteritems
   Series.keys

For more information on ``.at``, ``.iat``, ``.loc``, and
``.iloc``,  see the :ref:`indexing documentation <indexing>`.

Binary operator functions
-------------------------
.. autosummary::
   :toctree: api/

   Series.add
   Series.sub
   Series.subtract
   Series.mul
   Series.multiply
   Series.truediv
   Series.div
   Series.divide
   Series.floordiv
   Series.mod
   Series.pow
   Series.radd
   Series.rsub
   Series.rmul
   Series.rdiv
   Series.rtruediv
   Series.rfloordiv
   Series.rmod
   Series.rpow
   Series.round
   Series.lt
   Series.gt
   Series.le
   Series.ge
   Series.ne
   Series.eq
   Series.product

Function application, GroupBy & window
--------------------------------------
.. autosummary::
   :toctree: api/

   Series.apply
   Series.applymap
   Series.map
   Series.groupby
   Series.rolling
   Series.pipe

.. _api.series.stats:

Computations / descriptive stats
--------------------------------
.. autosummary::
   :toctree: api/

   Series.abs
   Series.all
   Series.any
   Series.autocorr
   Series.ceil
   Series.clip
   Series.corr
   Series.count
   Series.cov
   Series.cummax
   Series.cummin
   Series.cumprod
   Series.cumsum
   Series.describe
   Series.diff
   Series.digitize
   Series.factorize
   Series.floor
   Series.kurt
   Series.max
   Series.mean
   Series.median
   Series.min
   Series.mode
   Series.nlargest
   Series.nsmallest
   Series.prod
   Series.quantile
   Series.rank
   Series.skew
   Series.std
   Series.sum
   Series.var
   Series.kurtosis
   Series.unique
   Series.nunique
   Series.is_unique
   Series.is_monotonic
   Series.is_monotonic_increasing
   Series.is_monotonic_decreasing
   Series.value_counts

Reindexing / selection / label manipulation
-------------------------------------------
.. autosummary::
   :toctree: api/

   Series.add_prefix
   Series.add_suffix
   Series.drop
   Series.drop_duplicates
   Series.equals
   Series.head
   Series.isin
   Series.reindex
   Series.rename
   Series.reset_index
   Series.reverse
   Series.sample
   Series.set_mask
   Series.take
   Series.tail
   Series.tile
   Series.where
   Series.mask

Missing data handling
---------------------
.. autosummary::
   :toctree: api/

   Series.dropna
   Series.fillna
   Series.isna
   Series.isnull
   Series.nans_to_nulls
   Series.notna
   Series.notnull
   Series.replace

Reshaping, sorting
------------------
.. autosummary::
   :toctree: api/

   Series.argsort
   Series.interleave_columns
   Series.sort_values
   Series.sort_index
   Series.explode
   Series.scatter_by_map
   Series.searchsorted
   Series.repeat
   Series.transpose

Combining / comparing / joining / merging / encoding
----------------------------------------------------
.. autosummary::
   :toctree: api/

   Series.append
   Series.update
   Series.label_encoding
   Series.one_hot_encoding

Numerical operations
~~~~~~~~~~~~~~~~~~~~
.. autosummary::
   :toctree: api/

   Series.acos
   Series.asin
   Series.atan
   Series.cos
   Series.exp
   Series.log
   Series.sin
   Series.sqrt
   Series.tan

Time Series-related
-------------------
.. autosummary::
   :toctree: api/

   Series.shift

Accessors
---------

pandas provides dtype-specific methods under various accessors.
These are separate namespaces within :class:`Series` that only apply
to specific data types.

=========================== =================================
Data Type                   Accessor
=========================== =================================
Datetime, Timedelta         :ref:`dt <api.series.dt>`
String                      :ref:`str <api.series.str>`
Categorical                 :ref:`cat <api.series.cat>`
List                        :ref:`list <api.series.list>`
Struct                      :ref:`struct <api.series.struct>`
=========================== =================================

.. _api.series.dt:

Datetimelike properties
~~~~~~~~~~~~~~~~~~~~~~~

``Series.dt`` can be used to access the values of the series as
datetimelike and return several properties.
These can be accessed like ``Series.dt.<property>``.

Datetime properties
^^^^^^^^^^^^^^^^^^^
.. currentmodule:: cudf.core.series.DatetimeProperties

.. autosummary::
   :toctree: api/

   day
   dayofweek
   dayofyear
   days_in_month
   day_of_year
   hour
   minute
   month
   second
   weekday
   year
   is_leap_year
   is_month_start
   is_month_end
   is_quarter_start
   is_quarter_end
   is_year_start
   is_year_end
   quarter

Datetime methods
^^^^^^^^^^^^^^^^

.. autosummary::
   :toctree: api/

   strftime
   isocalendar
   ceil
   floor
   round


Timedelta properties
^^^^^^^^^^^^^^^^^^^^

.. currentmodule:: cudf.core.series.TimedeltaProperties
.. autosummary::
   :toctree: api/

   components
   days
   microseconds
   nanoseconds
   seconds

.. _api.series.str:
.. include:: string_handling.rst


..
    The following is needed to ensure the generated pages are created with the
    correct template (otherwise they would be created in the Series/Index class page)

..
    .. currentmodule:: cudf
    .. autosummary::
       :toctree: api/
       :template: autosummary/accessor.rst

       Series.str
       Series.cat
       Series.dt
       Index.str

.. _api.series.cat:

Categorical accessor
~~~~~~~~~~~~~~~~~~~~

Categorical-dtype specific methods and attributes are available under
the ``Series.cat`` accessor.

.. currentmodule:: cudf.core.column.categorical.CategoricalAccessor
.. autosummary::
   :toctree: api/

   categories
   ordered
   codes
   reorder_categories
   add_categories
   remove_categories
   set_categories
   as_ordered
   as_unordered


.. _api.series.list:

List handling
~~~~~~~~~~~~~

``Series.list`` can be used to access the values of the series as
lists and apply list methods to it. These can be accessed like
``Series.list.<function/property>``.

.. currentmodule:: cudf.core.column.lists.ListMethods
.. autosummary::
   :toctree: api/

   concat
   contains
   get
   len
   sort_values
   take
   unique


.. _api.series.struct:

Struct handling
~~~~~~~~~~~~~~~

``Series.struct`` can be used to access the values of the series as
Structs and apply struct methods to it. These can be accessed like
``Series.struct.<function/property>``.

.. currentmodule:: cudf.core.column.struct.StructMethods
.. autosummary::
   :toctree: api/

   field
   explode


Serialization / IO / conversion
-------------------------------
.. currentmodule:: cudf
.. autosummary::
   :toctree: api/

   Series.to_array
   Series.to_arrow
   Series.to_dlpack
   Series.to_frame
   Series.to_gpu_array
   Series.to_hdf
   Series.to_json
   Series.to_pandas
   Series.to_string
   Series.from_arrow
   Series.from_categorical
   Series.from_masked_array
   Series.from_pandas
   Series.hash_values
