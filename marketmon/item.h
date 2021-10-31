#pragma once

// Main includes
#include <string>

// Using directives
using std::string;

// Typedefs
typedef unsigned int uint;
typedef unsigned long ulong;

/// <summary>
/// Object type for storing information regarding OSRS items.
/// </summary>
class Item
{
	protected:
		string name;
		uint id;
		ulong price;
		ulong lastprice;

	public:
		Item(uint);

		/// <summary>
		/// Acquires the name of this item.
		/// </summary>
		/// <returns>The display name of this <see cref="Item" /> as a <see cref="string" /> form.</returns>
		string getName()
		{
			return name;
		}

		/// <summary>
		/// Acquires the Item ID of this <see cref="Item" />.
		/// </summary>
		/// <returns>The Item ID of this <see cref="Item" /> as a <see cref="uint" />.</returns>
		uint getItemID()
		{
			return id;
		}

		/// <summary>
		/// Retrieves latest item data from the Grand Exchange API and updates
		/// the relevant data stored in this object.
		/// </summary>
		void update();

		/// <summary>
		/// Acquires the current price of this <see cref="Item" />.
		/// </summary>
		/// <param name="fresh">If <see langword="true" />, forces an update on this <see cref="Item" />.</param>
		/// <returns>The Grand Exchange price of this <see cref="Item" />.</returns>
		ulong getPrice(bool fresh = false);

		/// <summary>
		/// Calculates the change in the price of this <see cref="Item" /> since it was last updated.
		/// </summary>
		/// <param name="fresh">If <see langword="true" />, forces an update on this <see cref="Item" />.</param>
		/// <returns>The change of this <see cref="Item" />'s Grand Exchange price since it was last updated.</returns>
		long getPriceDelta(bool fresh = false);
};
