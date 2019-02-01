/*
 * opencog/atoms/core/TruthValueOfLink.h
 *
 * Copyright (C) 2018 Linas Vepstas
 * All Rights Reserved
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU Affero General Public License v3 as
 * published by the Free Software Foundation and including the exceptions
 * at http://opencog.org/wiki/Licenses
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU Affero General Public License
 * along with this program; if not, write to:
 * Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 */

#ifndef _OPENCOG_TRUTH_VALUE_OF_LINK_H
#define _OPENCOG_TRUTH_VALUE_OF_LINK_H

#include <opencog/atoms/core/ValueOfLink.h>

namespace opencog
{
/** \addtogroup grp_atomspace
 *  @{
 */

/// The TruthValueOfLink returns the truth value on the indicated atom.
///
class TruthValueOfLink : public ValueOfLink
{
public:
	TruthValueOfLink(const HandleSeq&, Type=TRUTH_VALUE_OF_LINK);
	TruthValueOfLink(const Link &l);

	// Return a pointer to the extracted value.
	virtual ValuePtr execute() const;

	static Handle factory(const Handle&);
};

typedef std::shared_ptr<TruthValueOfLink> TruthValueOfLinkPtr;
static inline TruthValueOfLinkPtr TruthValueOfLinkCast(const Handle& h)
	{ return std::dynamic_pointer_cast<TruthValueOfLink>(h); }
static inline TruthValueOfLinkPtr TruthValueOfLinkCast(AtomPtr a)
	{ return std::dynamic_pointer_cast<TruthValueOfLink>(a); }

#define createTruthValueOfLink std::make_shared<TruthValueOfLink>

// ====================================================================

/// The StrengthOfLink returns the strength of a truth value on the
/// indicated atom. (Strength is the first of the sequence of floats).
///
class StrengthOfLink : public ValueOfLink
{
public:
	StrengthOfLink(const HandleSeq&, Type=STRENGTH_OF_LINK);
	StrengthOfLink(const Link &l);

	// Return a pointer to the extracted value.
	virtual ValuePtr execute() const;

	static Handle factory(const Handle&);
};

typedef std::shared_ptr<StrengthOfLink> StrengthOfLinkPtr;
static inline StrengthOfLinkPtr StrengthOfLinkCast(const Handle& h)
	{ return std::dynamic_pointer_cast<StrengthOfLink>(h); }
static inline StrengthOfLinkPtr StrengthOfLinkCast(AtomPtr a)
	{ return std::dynamic_pointer_cast<StrengthOfLink>(a); }

#define createStrengthOfLink std::make_shared<StrengthOfLink>

// ====================================================================

/// The ConfidenceOfLink returns the strength of a truth value on the
/// indicated atom. (Confidence is the first of the sequence of floats).
///
class ConfidenceOfLink : public ValueOfLink
{
public:
	ConfidenceOfLink(const HandleSeq&, Type=CONFIDENCE_OF_LINK);
	ConfidenceOfLink(const Link &l);

	// Return a pointer to the extracted value.
	virtual ValuePtr execute() const;

	static Handle factory(const Handle&);
};

typedef std::shared_ptr<ConfidenceOfLink> ConfidenceOfLinkPtr;
static inline ConfidenceOfLinkPtr ConfidenceOfLinkCast(const Handle& h)
	{ return std::dynamic_pointer_cast<ConfidenceOfLink>(h); }
static inline ConfidenceOfLinkPtr ConfidenceOfLinkCast(AtomPtr a)
	{ return std::dynamic_pointer_cast<ConfidenceOfLink>(a); }

#define createConfidenceOfLink std::make_shared<ConfidenceOfLink>

/** @}*/
}

#endif // _OPENCOG_TRUTH_VALUE_OF_LINK_H
